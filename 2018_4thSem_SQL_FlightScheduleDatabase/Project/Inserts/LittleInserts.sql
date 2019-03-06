--inserty do mniejszych tabel

--linie lotnicze
INSERT INTO airlines (airline_name, airline_country) VALUES ('TAP Portugal', 'Portugal');
INSERT INTO airlines (airline_name, airline_country) VALUES ('Iberia', 'Spain');
INSERT INTO airlines (airline_name, airline_country) VALUES ('Alitalia', 'Italy');
COMMIT;

--lotniska
INSERT INTO airports (airport_code, airport_name, airport_city, airport_country) VALUES ('VLC', 'Valencia Airport', 'Valencia', 'Spain');
INSERT INTO airports (airport_code, airport_name, airport_city, airport_country) VALUES ('KBP', 'Boryspil International Airport', 'Kiev', 'Ukraine');
INSERT INTO airports (airport_code, airport_name, airport_city, airport_country) VALUES ('BTS', 'M. R. Stefanik Airport', 'Bratislava', 'Slovakia');
COMMIT;

--turysci
INSERT INTO tourists VALUES (0,'Cristiano', 'Ronaldo', 'Portugal');
INSERT INTO tourists VALUES (0,'Lionel', 'Messi', 'Argentina');
INSERT INTO tourists VALUES (0,'Edison', 'Cavani', 'Uruguay');
INSERT INTO tourists VALUES (0,'Steve', 'Mandanda', 'France');
COMMIT;

--loty
INSERT INTO flights VALUES (0, 'EgyptAir', '2018-01-28 15:50', 'VLC', '2018-01-30 16:20', 'KBP', 1500);
INSERT INTO flights VALUES (0, 'Turkish Airlines', '2018-02-05 15:50', 'MAD', '2018-02-06 16:51', 'VLC', 230);
INSERT INTO flights VALUES (0, 'China Eastern Airlines', '2018-03-21 16:30', 'JFK', '2018-03-21 17:31', 'BTS', 1999);
COMMIT;

--rezerwacje
INSERT INTO reservations (tourist_id) VALUES (3004);
INSERT INTO reservations (tourist_id) VALUES (3003);
INSERT INTO reservations (tourist_id) VALUES (3002);
INSERT INTO reservations (tourist_id) VALUES (3001);
COMMIT;

--loty do rezerwacji
INSERT INTO flights_reservations (reservation_id,flight_id) VALUES (104,1);
INSERT INTO flights_reservations (reservation_id,flight_id) VALUES (104,2);
INSERT INTO flights_reservations (reservation_id,flight_id) VALUES (104,3);
INSERT INTO flights_reservations (reservation_id,flight_id) VALUES (104,4);
INSERT INTO flights_reservations (reservation_id,flight_id) VALUES (104,5);

INSERT INTO flights_reservations (reservation_id,flight_id) VALUES (103,11);
INSERT INTO flights_reservations (reservation_id,flight_id) VALUES (103,12);
INSERT INTO flights_reservations (reservation_id,flight_id) VALUES (103,13);

INSERT INTO flights_reservations (reservation_id,flight_id) VALUES (102,21);
INSERT INTO flights_reservations (reservation_id,flight_id) VALUES (102,22);

INSERT INTO flights_reservations (reservation_id,flight_id) VALUES (101,31);
COMMIT;

