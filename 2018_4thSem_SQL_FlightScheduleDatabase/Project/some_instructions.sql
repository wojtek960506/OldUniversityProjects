insert into flights values (    flights_seq.nextval,
                                'Ryanair',
                                '2018-04-30 21:24',
                                'WMI',
                                '2018-12-10 12:31',
                                'LUZ',
                                3000 );
                            
select * from flights order by flight_id desc;
select * from flights_auxiliary order by flight_id desc;

select * from reservations order by reservation_id desc;
select * from flights_reservations where flight_id = 10 order by reservation_id ;

select * from airlines order by airline_id;
select * from airports order by airport_id;
select * from countries order by country_id desc;
select * from flights order by flight_id;
select * from reservations order by reservation_id desc;
select * from reservations where reservation_id = 101 order by reservation_id;
select * from tourists order by tourist_id;

select f.flight_price from FLIGHTS_RESERVATIONS join FLIGHTS f ON flights_reservations.flight_id = f.flight_id where flights_reservations.reservation_id = 1001;

INSERT INTO reservations(reservation_id,tourist_id) values (reservations_seq.nextval,1000);


CREATE TABLE interval123(
    interval1 INTERVAL DAY (2) TO SECOND
);

CREATE TABLE char123(
    char1 CHAR(20)
);

CREATE TABLE int123(
    int1 INTEGER
);


--DECLARE
  --  char_b CHAR(20);
    --char_e CHAR(20);
    
INSERT INTO int123 VALUES ( to_number( extract(year from to_date('201805062121','yyyymmddhh24mi') )  ) );  
    
 select * from int123;   
    
INSERT INTO char123 VALUES (  to_char((SELECT interval1 from interval123 where interval1 = '00 2:30:00')) );
select * from char123;

INSERT INTO flights_reservations VALUES (34,2); 
INSERT INTO flights_reservations VALUES (35,2);
INSERT INTO flights_reservations VALUES (36,2);
INSERT INTO flights_reservations VALUES (37,2);
INSERT INTO flights_reservations VALUES (38,2);

select * from discounts;
select * from reservations where reservation_id = 2;
select flight_id,flight_price from flights where flight_id in (33,34,35,36,37);
select * from flights_reservations where reservation_id = 2;

DELETE FROM flights_reservations where flight_id = 97;
DELETE FROM flights_reservations where flight_id = 40 and reservation_id = 1;
delete from reservations where reservation_id = 2;
delete from tourists where tourist_id = 1971;

select * from logs;

select count(*) from tourists;
delete from tourists where tourist_id = (select max(tourist_id) from tourists);

select * from tourists where tourist_id = 999;