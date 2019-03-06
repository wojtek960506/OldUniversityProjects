--commit;

DROP TABLE logs;
CREATE TABLE logs (
    date_of_operation      TIMESTAMP(9) NOT NULL,               
    relation               VARCHAR2(100) NOT NULL,
    operation             VARCHAR2(50) NOT NULL
);
--triger testowy, uruchamia sie kiedy dodano turyste
CREATE OR REPLACE TRIGGER SaveTouristInsert
AFTER INSERT ON tourists
BEGIN
INSERT INTO logs
VALUES(sysdate, 'TOURISTS', 'INSERT');
END;
/
CREATE OR REPLACE TRIGGER SaveTouristDelete
AFTER INSERT ON tourists
BEGIN
INSERT INTO logs
VALUES(sysdate, 'TOURISTS', 'DELETE');
END;
/


--trigery do wstawiania indeksow
CREATE OR REPLACE TRIGGER countries_id_trigger
BEFORE INSERT ON countries
FOR EACH ROW
BEGIN
  SELECT countries_seq.nextval INTO :new.country_id FROM dual;
END;
/
CREATE OR REPLACE TRIGGER airlines_id_trigger
BEFORE INSERT ON airlines
FOR EACH ROW
BEGIN
  SELECT airlines_seq.nextval INTO :new.airline_id FROM dual;
END;
/
CREATE OR REPLACE TRIGGER airports_id_trigger
BEFORE INSERT ON airports
FOR EACH ROW
BEGIN
  SELECT airports_seq.nextval INTO :new.airport_id FROM dual;
END;
/
CREATE OR REPLACE TRIGGER flights_id_trigger
BEFORE INSERT ON flights
FOR EACH ROW
BEGIN
  SELECT flights_seq.nextval INTO :new.flight_id FROM dual;
END;
/
CREATE OR REPLACE TRIGGER tourists_id_trigger
BEFORE INSERT ON tourists
FOR EACH ROW
BEGIN
  SELECT tourists_seq.nextval INTO :new.tourist_id FROM dual;
END;
/
CREATE OR REPLACE TRIGGER discounts_id_trigger
BEFORE INSERT ON discounts
FOR EACH ROW
BEGIN
  SELECT discounts_seq.nextval INTO :new.discount_id FROM dual;
END;
/


CREATE OR REPLACE TRIGGER reservations_id_trigger
BEFORE INSERT ON reservations
FOR EACH ROW
BEGIN
  SELECT reservations_seq.nextval INTO :new.reservation_id FROM dual;
END;
/


------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
--triger zapewniajacy nas o tym, ze nie dodamy zbyt dugiego lotu
CREATE OR REPLACE TRIGGER GoodFlightDetails
BEFORE INSERT ON flights
FOR EACH ROW
DECLARE
    
    interval_max INTERVAL DAY (2) TO SECOND := '0 15:00:00'; --length of flight may be maximum 15 hours
    interval_min INTERVAL DAY (2) TO SECOND := '0 1:00:00'; --length of flight may be minimum 1 hour
    
    --for another solution, maybe faster
    interval_new INTERVAL DAY (2) TO SECOND; --we will draw its value 
    interval_char VARCHAR2(12);
    hour_n NUMERIC(2); --we will draw new flight hour
    minute_n NUMERIC(2); --we will draw new flight minutes
    
     
    --to know range of randomization for airport and airline
    apc NUMERIC(4); --airport count 
    
    it1 NUMERIC (10) := 0; --to check how many times was in while loop with bad time
    
    --to store data of inserted flight
    f_id NUMERIC(4);
    dep_time TIMESTAMP(1);
    arr_time TIMESTAMP(1);
    dep_airp_id NUMERIC(4);
    arr_airp_id NUMERIC(4);
    dep_airp_c CHAR(3);   --departure airport code
    arr_airp_c CHAR(3);   --arrival airport code
    
    --to eventually randomize arrival time
    arr_year NUMERIC(4);
    arr_month NUMERIC(2);
    arr_day NUMERIC(2);
    arr_hour NUMERIC(2);
	arr_minute NUMERIC(2);
    arr_time_char CHAR(20);
    
    airl_name VARCHAR(100);
    p NUMERIC (4);
BEGIN
        
        --we want to check if just added time values and airports of flight  are correct
        dep_time := :new.flight_departure_time;
        arr_time := :new.flight_arrival_time;
        dep_airp_c := :new.flight_departure_airport;
        arr_airp_c := :new.flight_arrival_airport;
        
        SELECT airport_id into dep_airp_id from airports where airport_code = dep_airp_c;
        SELECT airport_id into arr_airp_id from airports where airport_code = arr_airp_c;
        
        --we will use it for eventually changing of arrival airport
        SELECT count(*) into apc from airports;
        
        --for eventually update in the end
        f_id := :new.flight_id;
        p := :new.flight_price;
        airl_name := :new.airline_name;
           
------------------------------------------------------------------------------------------------------------------------------------------------------------------    
        IF ( arr_time < dep_time + interval_min OR arr_time > dep_time + interval_max OR arr_airp_id = dep_airp_id OR p < 100 OR p > 2000) THEN
            
            if ( arr_time < dep_time + interval_min OR arr_time > dep_time + interval_max ) then 
                --new arrival time
                hour_n := dbms_random.value(1, 14);
                minute_n := dbms_random.value(0, 59);
                interval_char := to_char( '0 ' || hour_n || ':' || minute_n || ':00' );
                interval_new := interval_char;
                arr_time := dep_time + interval_new;
            end if;
            
            if ( arr_airp_id = dep_airp_id ) then
                --another randomization of arrival airport
                arr_airp_id := dbms_random.value(1,apc);
            end if;
            
            if( p < 100 OR p > 2000 ) then
                --randomization of flight price
                p := dbms_random.value(100,2000);
            end if;
            
            it1 := it1 + 1;
        END IF;
------------------------------------------------------------------------------------------------------------------------------------------------------------------

        --new arrival airport
        SELECT airport_code into arr_airp_c from airports where airport_id = arr_airp_id;
        
        IF it1 > 0 THEN
            --INSERT INTO flights_auxiliary VALUES (f_id,airl_name,dep_time,dep_airp_c,arr_time,arr_airp_c,p);            
            :new.flight_id := f_id;
            :new.airline_name := airl_name;
            :new.flight_departure_time := dep_time;
            :new.flight_departure_airport := dep_airp_c;
            :new.flight_arrival_time := arr_time;
            :new.flight_arrival_airport := arr_airp_c;
            :new.flight_price := p;
        END IF;
                                        
        --INSERT INTO KURCZAK VALUES (it1);   
END;
/
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


CREATE OR REPLACE TRIGGER change_price_after_insert
AFTER INSERT ON flights_reservations
FOR EACH ROW
DECLARE 
    f_id NUMERIC(4);
    r_id NUMERIC(4);
    f_p INTEGER; --price of flight
    prev_r_p INTEGER; --price of reservation before adding this flight
    after_r_p INTEGER; --price of reservation after adding this flight
    
    price_wo_disc INTEGER;
    new_price INTEGER;
    
    num_of_fl INTEGER;
    percentage INTEGER;
    
    prev_r_n INTEGER; --number of flights in reservation before adding this flight
    after_r_n INTEGER; --number of flights in reservation after adding this flight
BEGIN
    
    f_id := :new.flight_id; --flight_id of new flight reservation
    r_id := :new.reservation_id; --reservation_id of new flight reservation
    
    DELETE FROM discounts WHERE reservation_id = r_id;
    
    SELECT reservation_price_wo_discounts INTO prev_r_p FROM reservations where reservation_id = r_id;
    SELECT flight_price INTO f_p FROM flights where flight_id = f_id;
    SELECT reservation_number_of_flights INTO prev_r_n FROM reservations where reservation_id = r_id;
    
    after_r_p := prev_r_p + f_p;
    after_r_n := prev_r_n + 1;
    
    num_of_fl := after_r_n; --number of flights after update
    price_wo_disc := after_r_p; --price without discounts
    new_price := after_r_p; --in case of any discounts this price will be unchanged
    if num_of_fl = 2  then
        percentage := 5;
        new_price := price_wo_disc - (price_wo_disc * percentage / 100);
        INSERT INTO discounts (reservation_id,discount_percentage,discount_name) VALUES (r_id,percentage,'2 FLIGHTS -> 5% DISCOUNT'); 
    end if;
    if num_of_fl = 3  then
        percentage := 10;
        new_price := price_wo_disc - (price_wo_disc * percentage / 100);
        INSERT INTO discounts (reservation_id,discount_percentage,discount_name) VALUES (r_id,percentage,'3 FLIGHTS -> 10% DISCOUNT'); 
    end if;
    
    if num_of_fl = 4 OR num_of_fl > 4 then
        percentage := 20;
        new_price := price_wo_disc - (price_wo_disc * percentage / 100);
        INSERT INTO discounts (reservation_id,discount_percentage,discount_name) VALUES (r_id,percentage,'4 OR MORE FLIGHTS -> 20% DISCOUNT');
    end if;
    
    --UPDATE reservations SET reservation_price = new_price where reservation_id = r_id;
    UPDATE reservations SET reservation_price = new_price,
                            reservation_price_wo_discounts = after_r_p,
                            reservation_number_of_flights = after_r_n
                            where reservation_id = r_id;    
END;
/

CREATE OR REPLACE TRIGGER before_delete_reservation
BEFORE DELETE ON reservations
FOR EACH ROW
BEGIN
    if(:old.reservation_number_of_flights > 0) then
        
        delete from flights_reservations where reservation_id = :old.reservation_id;
    end if;
END;
/



----------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------
--to mi nie chce dobrze dzialac, wiec zakladam, ¿e nie mozna usuwac pojedynczych lotow z rezerwacji
/*
drop trigger change_price_before_delete;

CREATE OR REPLACE TRIGGER change_price_before_delete
BEFORE DELETE ON flights_reservations
FOR EACH ROW
DECLARE
    f_id NUMERIC(4);
    r_id NUMERIC(4);
    f_p INTEGER; --price of flight
    prev_r_p INTEGER; --price of reservation before adding this flight
    after_r_p INTEGER; --price of reservation after adding this flight
    
    price_wo_disc INTEGER;
    new_price INTEGER;
    
    num_of_fl INTEGER;
    percentage INTEGER;
    
    prev_r_n INTEGER; --number of flights in reservation before adding this flight
    after_r_n INTEGER; --number of flights in reservation after adding this flight
    
BEGIN
        f_id := :old.flight_id; --flight_id of new flight reservation
        r_id := :old.reservation_id; --reservation_id of new flight reservation
        DELETE FROM discounts where reservation_id = r_id;
        
        SELECT reservation_price_wo_discounts INTO prev_r_p FROM reservations where reservation_id = r_id;
        SELECT flight_price INTO f_p FROM flights where flight_id = f_id;
        SELECT reservation_number_of_flights INTO prev_r_n FROM reservations where reservation_id = r_id;
        
        after_r_p := prev_r_p - f_p;
        after_r_n := prev_r_n - 1;
        
        num_of_fl := after_r_n; --number of flights after update
        price_wo_disc := after_r_p; --price without discounts
        new_price := after_r_p; --in case of any discounts this price will be unchanged
        if num_of_fl = 2  then
            percentage := 5;
            new_price := price_wo_disc - (price_wo_disc * percentage / 100);
            INSERT INTO discounts VALUES ( discounts_seq.nextval,r_id,percentage,'2 FLIGHTS -> 5% DISCOUNT'); 
        end if;
        if num_of_fl = 3  then
            percentage := 10;
            new_price := price_wo_disc - (price_wo_disc * percentage / 100);
            INSERT INTO discounts VALUES ( discounts_seq.nextval,r_id,percentage,'3 FLIGHTS -> 10% DISCOUNT'); 
        end if;
        
        if num_of_fl = 4 OR num_of_fl > 4 then
            percentage := 20;
            new_price := price_wo_disc - (price_wo_disc * percentage / 100);
            INSERT INTO discounts VALUES ( discounts_seq.nextval,r_id,percentage,'4 OR MORE FLIGHTS -> 20% DISCOUNT');
        end if;
        
        --UPDATE reservations SET reservation_price = new_price where reservation_id = r_id;
        UPDATE reservations SET reservation_price = new_price,
                                reservation_price_wo_discounts = after_r_p,
                                reservation_number_of_flights = after_r_n
                                where reservation_id = r_id;    
    
END;
/
*/



--commit;
 /*
CREATE OR REPLACE TRIGGER add_discount_amount_of_flights
AFTER UPDATE ON reservations
FOR EACH ROW
DECLARE
    fl_id INTEGER;
    reserv_id INTEGER;
    num_of_fl INTEGER;
    fl_dep_time TIMESTAMP(1);
    fl_arr_time TIMESTAMP(1);
    flight_length INTERVAL DAY (2) TO SECOND;
BEGIN
    --fl_id := :new.flight_id;
    reserv_id := :new.reservation_id;
    num_of_fl := :new.reservation_number_of_flights;
    --maybe it will work with interval
    -- select flight_departure_time into fl_dep_time from flights where flight_id = fl_id;
    --select flight_arrival_time into fl_arr_time from flights where flight_id = fl_id;
    --flight_length := fl_arr_time - fl_dep_time;
    
    --number of flights
    --select reservation_number_of_flights into num_of_fl from reservations where reservation_id = reserv_id;
    
    
    if num_of_fl = 2  then INSERT INTO discounts VALUES ( discounts_seq.nextval,reserv_id,5,'2 FLIGHTS -> 5% DISCOUNT'); end if;
    if num_of_fl = 3  then INSERT INTO discounts VALUES ( discounts_seq.nextval,reserv_id,10,'3 FLIGHTS -> 10% DISCOUNT'); end if;
    if num_of_fl = 4  then INSERT INTO discounts VALUES ( discounts_seq.nextval,reserv_id,20,'2 FLIGHTS -> 15% DISCOUNT'); end if;
END;
/
*/
/*
CREATE OR REPLACE TRIGGER change_price_after_discount
AFTER INSERT ON discounts
FOR EACH ROW
DECLARE
    reserv_id INTEGER;
    percentage INTEGER; --percentage of discount
    price_wo_disc INTEGER;
    new_price INTEGER;
BEGIN
    reserv_id := :new.reservation_id;
    percentage := :new.discount_percentage;
    select reservation_price_wo_discounts into price_wo_disc from reservations where reservation_id = reserv_id;
    new_price := price_wo_disc - (price_wo_disc * percentage / 100);
    
    UPDATE reservations SET reservation_price = new_price WHERE reservation_id = reserv_id;
    
END;
/
*/
--&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&--
--&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&--
-- sprawdz kiedys czy to dziala|sprawdz kiedys czy to dziala||sprawdz kiedys czy to dziala --
--&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&--
--&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&--
/*
CREATE OR REPLACE TRIGGER ValidTouristId
BEFORE INSERT ON reservations
FOR EACH ROW
DECLARE
    t_id INTEGER;
    r_id INTEGER;
    t_count INTEGER;
    t_min_id INTEGER;
    t_max_id INTEGER;
    c INTEGER := 0;
BEGIN
    r_id := :new.reservation_id;
    t_id := :new.tourist_id;
    SELECT COUNT(*) INTO t_count FROM tourists;
    SELECT MIN(tourist_id) INTO t_min_id FROM tourists;
    SELECT MAX(tourist_id) INTO t_max_id FROM tourists;
    
    IF ( t_id NOT IN (SELECT tourist_id FROM tourists) ) THEN
        t_id := dbms_random.value(t_min_id,t_max_id);
        c := c + 1;
    END IF;
    
    IF (c > 0) THEN
        INSERT INTO kurczak VALUES (9999);
        :new.tourist_id := t_id;
    END IF;
    
END;
/
*/
/*
--previous trigger now I ahve to change everything inside it
CREATE OR REPLACE TRIGGER change_reservation_price
AFTER INSERT ON flights_reservations
FOR EACH ROW
DECLARE 
    f_id NUMERIC(4);
    r_id NUMERIC(4);
    f_p INTEGER; --price of flight
    prev_r_p INTEGER; --price of reservation before adding this flight
    after_r_p INTEGER; --price of reservation after adding this flight
    
    prev_r_n INTEGER; --number of flights in reservation before adding this flight
    after_r_n INTEGER; --number of flights in reservation after adding this flight
BEGIN
    f_id := :new.flight_id; --flight_id of new flight reservation
    r_id := :new.reservation_id; --reservation_id of new flight reservation
    
    --
    SELECT reservation_price INTO prev_r_p FROM reservations where reservation_id = r_id;
    SELECT flight_price INTO f_p FROM flights where flight_id = f_id;
    SELECT reservation_number_of_flights INTO prev_r_n FROM reservations where reservation_id = r_id;
    
    after_r_p := prev_r_p + f_p;
    after_r_n := prev_r_n + 1;
    
    UPDATE reservations SET reservation_price = after_r_p,
                            reservation_price_wo_discounts = after_r_p,
                            reservation_number_of_flights = after_r_n
                            where reservation_id = r_id;    
    --after_r_p := 0;
    --prev_r_p := 0;
    --f_p := 0;
END;
/
*/