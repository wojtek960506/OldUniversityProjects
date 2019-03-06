--insert flight

set serveroutput on format wrapped;
set define off;

DELETE FROM flights;

DROP SEQUENCE flights_seq;

CREATE SEQUENCE flights_seq START WITH 1 INCREMENT BY 1 NOMAXVALUE;


DECLARE
    airl_id NUMERIC(4); --airline_id
    price NUMERIC(4); 
    
    airl_min_id INTEGER;
    airl_max_id INTEGER;
    airp_min_id INTEGER;
    airp_max_id INTEGER;
    
    interval_max INTERVAL DAY (2) TO SECOND := '0 15:00:00'; --length of flight may be maximum 15 hours
    interval_min INTERVAL DAY (2) TO SECOND := '0 1:00:00'; --length of flight may be minimum 1 hour
    
    --for randomize airports
    dep_airp_id NUMERIC(4);
    arr_airp_id NUMERIC(4);
    
    --for randomize airports
    dep_airp_c CHAR(3);   --departure airport
    arr_airp_c CHAR(3);   --arrival airport
    
    --to know range of randomization for airport and airline
    alc NUMERIC(4); --airline count
    apc NUMERIC(4); --airport count 
    
    it1 NUMERIC (10) := 0; --to check how many times was in while loop with bad time
    
    --to randomize departure time
    dep_year NUMERIC(4);
    dep_month NUMERIC(2);
    dep_day NUMERIC(2);
    dep_hour NUMERIC(2);
	dep_minute NUMERIC(2);
    dep_time_char CHAR(20);
    dep_time TIMESTAMP(1);
    
    --to randomize arrival time
    arr_year NUMERIC(4);
    arr_month NUMERIC(2);
    arr_day NUMERIC(2);
    arr_hour NUMERIC(2);
	arr_minute NUMERIC(2);
    arr_time_char CHAR(20);
    arr_time TIMESTAMP(1);
    
BEGIN
	FOR i IN 1..100 LOOP 
        
        SELECT MIN(airline_id) into airl_min_id from airlines;
        SELECT MAX(airline_id) into airl_max_id from airlines;
        SELECT MIN(airport_id) into airp_min_id from airports;
        SELECT MAX(airport_id) into airp_max_id from airports;
            
        SELECT count(*) into alc from airlines;
        SELECT count(*) into apc from airports;
    
        airl_id := dbms_random.value(airl_min_id, airl_max_id);
        price := dbms_random.value(100,2000);
        
        dep_airp_id := dbms_random.value(airp_min_id, airp_max_id);
        arr_airp_id := dbms_random.value(airp_min_id, airp_max_id);
        
        --randomization of departure time
        dep_year := 2018;
		dep_month := dbms_random.value(2,4);
        if(dep_month in (1,3,5,7,8,10,12)) then dep_day := dbms_random.value(1,31); end if;
        if(dep_month in (4,6,9,11)) then dep_day := dbms_random.value(1,30); end if;
        if(dep_month in (2)) then dep_day := dbms_random.value(1,28); end if;
        dep_hour := dbms_random.value(0,23);
        dep_minute := dbms_random.value(0,59);
        dep_time_char := to_char(dep_year) || to_char(dep_month,'99') || to_char(dep_day,'99') || to_char(dep_hour,'99') || to_char(dep_minute,'99');
        
        --randomization of arrival time
        arr_year := 2018;
		arr_month := dbms_random.value(2,4);
        if(arr_month in (1,3,5,7,8,10,12)) then arr_day := dbms_random.value(1,31); end if;
        if(arr_month in (4,6,9,11)) then arr_day := dbms_random.value(1,30); end if;
        if(arr_month in (2)) then arr_day := dbms_random.value(1,28); end if;
        arr_hour := dbms_random.value(0,23);
        arr_minute := dbms_random.value(0,59);
        arr_time_char := to_char(arr_year) || to_char(arr_month,'99') || to_char(arr_day,'99') || to_char(arr_hour,'99') || to_char(arr_minute,'99');
        
        dep_time := to_date(dep_time_char,'yyyymmddhh24mi');
        arr_time := to_date(arr_time_char,'yyyymmddhh24mi');
            
        --randomization of airports
        SELECT airport_code into dep_airp_c from airports where airport_id = dep_airp_id;
        SELECT airport_code into arr_airp_c from airports where airport_id = arr_airp_id;
        
        INSERT INTO flights
        (airline_name, flight_departure_time, flight_departure_airport, flight_arrival_time, flight_arrival_airport, flight_price)
        VALUES ( (SELECT airline_name FROM airlines WHERE airline_id = airl_id), dep_time, dep_airp_c,arr_time,arr_airp_c,price );                                 
	END LOOP;
END;
/

commit;





------------------------------------------------------------------------------------------------------------------------------------------------------------------    
        /*WHILE ( arr_time < dep_time + interval_min OR arr_time > dep_time + interval_max OR arr_airp_id = dep_airp_id) LOOP 
            
            if ( arr_time < dep_time + interval_min OR arr_time > dep_time + interval_max ) then 
                --another randomization of arrival date
                ----------------------------------------------------------------------------------------------------------------------------------------------
                arr_year := 2018;   
                arr_month := dbms_random.value(2,12);
                if(arr_month in (1,3,5,7,8,10,12)) then arr_day := dbms_random.value(1,31); end if;
                if(arr_month in (4,6,9,11)) then arr_day := dbms_random.value(1,30); end if;
                if(arr_month in (2)) then arr_day := dbms_random.value(1,28); end if;
                arr_hour := dbms_random.value(0,23);
                arr_minute := dbms_random.value(0,59);
                arr_time_char := to_char(arr_year) || to_char(arr_month,'99') || to_char(arr_day,'99') || to_char(arr_hour,'99') || to_char(arr_minute,'99');
                arr_time := to_date(arr_time_char,'yyyymmddhh24mi');
                ----------------------------------------------------------------------------------------------------------------------------------------------
            end if;
            
            if ( arr_airp_id = dep_airp_id ) then
                --another randomization of arrival airport
                arr_airp_id := dbms_random.value(1,apc);
            end if;
            
            it1 := it1 + 1;
        END LOOP;*/
------------------------------------------------------------------------------------------------------------------------------------------------------------------
