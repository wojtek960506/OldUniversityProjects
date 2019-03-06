--ilosc lot�w o cenie ponad 1000
select count(*) from flights where flight_price > 1000;
--ilo�� lot�w
select count(*) from flights;
--ilo�� turyst�w z pa�stw, kt�re wystepuja wsr�d turyst�w
select tourist_country, count(*) from tourists group by tourist_country order by tourist_country;

--pa�stwa z minimalna iloscia turyst�w
select tourist_country as country, count(*) as ilosc   
        from tourists 
        group by tourist_country 
        having count(*) = (select min(count(tourist_country)) from tourists group by tourist_country);

--panstwa z maksymalna iloscia turystow        
select tourist_country as country, count(*) as ilosc   
        from tourists 
        group by tourist_country 
        having count(*) = (select max(count(tourist_country)) from tourists group by tourist_country);
        
--sredni koszt lotu dla danej linii        
select airline_name, round(avg(flight_price),2) as average_cost_of_flight from flights group by airline_name; 

--maksymalny koszt lotu dla danej linii
select airline_name, max(flight_price) from flights group by airline_name; 

--minimalny koszt lotu dla danej linii
select airline_name, min(flight_price) from flights group by airline_name; 


--ilo�� lot�w dla danej linii        
select airline_name, count(*) from flights group by airline_name; 

--linie dla kt�rych ilo�c lot�w wynosi 1        
select airline_name, count(*) from flights group by airline_name having count(*) = 1;

--cena rezerwacji ka�dego turysty
select tourist_first_name, tourist_last_name, r.reservation_price from tourists natural join reservations r order by r.reservation_price;

--turysta, kt�ry ma najta�sza rezerwacje
select tourist_first_name, tourist_last_name, r.reservation_price from tourists natural join reservations r
        where r.reservation_price = (select min(reservation_price) from reservations);

--turysta, kt�ry ma najdro�sza rezerwacje
select tourist_first_name, tourist_last_name, r.reservation_price from tourists natural join reservations r
        where r.reservation_price = (select max(reservation_price) from reservations);

--turysci, kt�rzy maja cene rezerwacji wieksza niz srednia cena rezerwacji
select tourist_first_name, tourist_last_name, r.reservation_price from tourists natural join reservations r
        where r.reservation_price > (select avg(reservation_price) from reservations);
        
--ilosc turystow o takim samym nazwisku
select tourist_last_name, count(*) from tourists group by tourist_last_name order by count(*) desc;

--ilosc osob o tym samym imieniu i nazwisku
select tourist_last_name, tourist_first_name, count(*) from tourists group by tourist_last_name, tourist_first_name order by count(*) desc;


--srednia cena oraz ilosc lot�w dla kt�ych cena jest wy�sza niz 500 oraz nazwa linii lotniczej ko�czy si� na 'ines'
select round(avg(f.flight_price),2) as "�REDNIA CENA", count(*) "ILOSC LOT�W"
                            from flights_reservations fr join flights f on fr.flight_id = f.flight_id 
                            join airlines airl on airl.airline_name = f.airline_name
                            where (f.flight_price > 500 and f.airline_name = any((select airline_name from airlines where airline_name like '%ines')))
                            order by f.flight_departure_time;