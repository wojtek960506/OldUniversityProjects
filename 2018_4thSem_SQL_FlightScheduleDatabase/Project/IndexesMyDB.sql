 ALTER SESSION SET HASH_JOIN_ENABLED=TRUE;

drop index ind_tourist_last_name;
create index ind_tourist_last_name on tourists(tourist_last_name);

drop index ind_country_abbreviation;
create index ind_country_abbreviation on countries(country_abbreviation);

drop index ind_country_abbreviation_id;
create index ind_country_abbreviation_id on countries(country_abbreviation,country_id);

drop index ind_flight_price;
create index ind_flight_price on flights(flight_price);

 
--tutaj indeks ind_tourist_last_name nie jest u¿ywany
explain plan set statement_id = 'st1' for
select t.tourist_id, r.reservation_price from tourists t join reservations r on t.tourist_id = r.tourist_id where tourist_last_name = 'Kowalczyk';
select * from table (dbms_xplan.display(NULL,'st1','TYPICAL'));

--tutaj indeks ind_tourist_last_name jest u¿ywany i zyskujemy dziêki niemu mniejszy koszt
explain plan set statement_id = 'st2' for
select tourist_id from tourists where tourist_last_name = 'Rogalski';
select * from table (dbms_xplan.display(NULL,'st2','TYPICAL'));

--##########################################################################################################################################################--


--z indeksem ind_country_abbreviation mniejszy koszt
explain plan set statement_id = 'st3' for
select country_name from countries where country_abbreviation LIKE 'A%';
select * from table (dbms_xplan.display(NULL,'st3','TYPICAL'));


--z indeksem ind_country_abbreviation_id koszt sie nie zmienia poniewaz uzywany jest indeks zwiazany z unikalna wartoœcia country_id
explain plan set statement_id = 'st4' for
select country_name from countries where country_abbreviation LIKE 'A%' and (country_id between 5 and 15);
select * from table (dbms_xplan.display(NULL,'st4','TYPICAL'));

--indeks ind_country_abbreviation_id w join nic nie zmienia
explain plan set statement_id = 'st5' for
select c.country_name, a.airline_name from countries c join airlines a on c.country_name = a.airline_country where c.country_abbreviation like 'A%' and (c.country_id between 10 and 15);
select * from table (dbms_xplan.display(NULL,'st5','TYPICAL'));

--#########################################################################################################################################################################--

--bez wzgledu na indeks ind_flight_price koszty sa takie same. Ten indeks nie jest uzywany
--zapytanie ktore wyswietla info dla lotow o cenie wiekszej niz 500 i których nazwa linii konczy sie na 'ines' 
explain plan set statement_id = 'st6' for
select fr.reservation_id, f.flight_price, airl.airline_name
                            from flights_reservations fr join flights f on fr.flight_id = f.flight_id 
                            join airlines airl on airl.airline_name = f.airline_name
                            where (f.flight_price > 500 and f.airline_name = any((select airline_name from airlines where airline_name like '%ines')))
                            order by f.flight_departure_time;
select * from table (dbms_xplan.display(NULL,'st6','TYPICAL'));

--nie korzystamy z indeksu stworzonego przeze mnie
explain plan set statement_id = 'st7' for
select flight_id, flight_departure_time, flight_departure_airport, flight_arrival_time, flight_arrival_airport from flights
        where flight_price between 700 and 1000 order by flight_id;
select * from table (dbms_xplan.display(NULL,'st7','TYPICAL'));

--korzystamy z indeksu ind_flight_price -> koszt jest wtedy mniejszy
explain plan set statement_id = 'st8' for
select flight_id,flight_departure_airport,flight_arrival_airport from flights where flight_price between 1000 and 1100;
select * from table (dbms_xplan.display(NULL,'st8','TYPICAL'));


drop index ind_flight_price;
create index ind_flight_price on flights(flight_price);


explain plan for
select airl.airline_id,f.flight_id from flights f natural join airlines airl where flight_price < 500;
select * from table (dbms_xplan.display);

drop index ind_tourist_last_name;
create index ind_tourist_last_name on tourists(tourist_last_name);
drop index ind_country_abbreviation;
create index ind_country_abbreviation on countries(country_abbreviation);
drop index ind_reservation_price;
create index ind_reservation_price on reservations(reservation_price);
drop index ind_discount_name;
create index ind_discount_name on discounts(discount_name);

---------------------------------------------------------------------------------------------------------------------------------------------------
--nested loop z indeksami
drop index ind_tourist_last_name;
create index ind_tourist_last_name on tourists(tourist_last_name);
drop index ind_country_abbreviation;
create index ind_country_abbreviation on countries(country_abbreviation);
explain plan for
select t.tourist_last_name, c.country_abbreviation from tourists t join countries c on t.tourist_country = c.country_name; 
select * from table (dbms_xplan.display);

--wymuszony hash_join z nested loopa bez indeksow ale z hintem
drop index ind_tourist_last_name;
drop index ind_country_abbreviation;
explain plan for
select /*+ use_hash(t c) */ t.tourist_last_name, c.country_abbreviation from tourists t join countries c on t.tourist_country = c.country_name; 
select * from table (dbms_xplan.display);

--wymuszony sort merge join z nested loopa bez indeksow ale z hintem
drop index ind_tourist_last_name;
drop index ind_country_abbreviation;
explain plan for
select /*+ use_merge(t c) */ t.tourist_last_name, c.country_abbreviation from tourists t join countries c on t.tourist_country = c.country_name; 
select * from table (dbms_xplan.display);
-------------------------------------------------------------------------------------------------------------------------------------------------------


-------------------------------------------------------------------------------------------------------------------------------------------------------

--kolejny nested loop, bo inne mi w ogole nie chca wyjsc
drop index ind_tourist_last_name;
create index ind_tourist_last_name on tourists(tourist_last_name);
drop index ind_reservation_price;
create index ind_reservation_price on reservations(reservation_price);
explain plan for
select t.tourist_last_name, r.reservation_price from tourists t natural join reservations r; 
select * from table (dbms_xplan.display);

--wymuszony hash join z nested loopa bez indeksow
drop index ind_tourist_last_name;
drop index ind_reservation_price;
explain plan for
select /*+ use_hash(t r) */ t.tourist_last_name, r.reservation_price from tourists t natural join reservations r; 
select * from table (dbms_xplan.display);

--wymuszony sort merge join z nested loopa bez indeksow
drop index ind_tourist_last_name;
drop index ind_reservation_price;
explain plan for
select /*+ use_merge(t r) */ t.tourist_last_name, r.reservation_price from tourists t natural join reservations r; 
select * from table (dbms_xplan.display);



---------------------------------
----jakies inne nieudane proby
explain plan for
select d.*, r.* from discounts d join reservations r on r.reservation_id = d.reservation_id;
select * from table (dbms_xplan.display);

explain plan for
select d.discount_name, r.reservation_price from discounts d join reservations r using(reservation_id);
select * from table (dbms_xplan.display);
