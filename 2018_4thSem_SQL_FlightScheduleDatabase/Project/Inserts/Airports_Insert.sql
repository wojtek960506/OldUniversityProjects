--insert airports

select * from airports;

DELETE FROM airports;

DROP SEQUENCE   airports_seq;
CREATE SEQUENCE airports_seq START WITH 1 INCREMENT BY 1 NOMAXVALUE;


INSERT INTO airports  (airport_code,airport_name,airport_city,airport_country) VALUES 
					  ('LHR', 'Heathrow Airport', 'London', 'United Kingdom' );
INSERT INTO airports  (airport_code,airport_name,airport_city,airport_country) VALUES 
					  ('FRA', 'Frankfurt Airport', 'Frankfurt', 'Germany' );
INSERT INTO airports  (airport_code,airport_name,airport_city,airport_country) VALUES 
					  ('JFK', 'John F. Kennedy International Airport', 'New York', 'United States' );
INSERT INTO airports  (airport_code,airport_name,airport_city,airport_country) VALUES 
					  ('EWR', 'Newark Liberty International Airport', 'Newark', 'United States' );
INSERT INTO airports  (airport_code,airport_name,airport_city,airport_country) VALUES 
					  ('LAS', 'Mccarran International Airport', 'Las Vegas', 'United States' );
INSERT INTO airports  (airport_code,airport_name,airport_city,airport_country) VALUES 
					  ('WAW', 'Warsaw Chopin Airport', 'Warsaw', 'Poland' );
INSERT INTO airports  (airport_code,airport_name,airport_city,airport_country) VALUES 
					  ('WMI', 'Warsaw Modlin Airport', 'Nowy Dwór Mazowiecki', 'Poland' );
INSERT INTO airports  (airport_code,airport_name,airport_city,airport_country) VALUES 
					  ('WRO', 'Copernicus Airport Wroclaw', 'Wroclaw', 'Poland' );
INSERT INTO airports  (airport_code,airport_name,airport_city,airport_country) VALUES 
					  ('LUZ', 'Lublin Airport', 'Œwidnik', 'Poland' );
INSERT INTO airports  (airport_code,airport_name,airport_city,airport_country) VALUES 
					  ('BCN', 'Barcelona-El Prat Airport', 'Barcelona', 'Spain' );
INSERT INTO airports  (airport_code,airport_name,airport_city,airport_country) VALUES 
					  ('MAD', 'Adolfo Suarez Madrid-Barajas Airport', 'Madrid', 'Spain' );
INSERT INTO airports  (airport_code,airport_name,airport_city,airport_country) VALUES 
					  ('OPO', 'Francisco Sa Carneiro Airport', 'Porto', 'Portugal' );
INSERT INTO airports  (airport_code,airport_name,airport_city,airport_country) VALUES 
					  ('TFN', 'Tenerife North Airport', 'San Cristobal de La Laguna', 'Spain' );
INSERT INTO airports  (airport_code,airport_name,airport_city,airport_country) VALUES 
					  ('TFS', 'Tenerife South Airport', 'Granadilla de Abona', 'Spain' );
INSERT INTO airports  (airport_code,airport_name,airport_city,airport_country) VALUES 
					  ('CIA', 'Ciampino-G.B. Pastine International Airport', 'Rome', 'Italy' );
INSERT INTO airports  (airport_code,airport_name,airport_city,airport_country) VALUES 
					  ('FCO', 'Leonardo da Vinci-Fiumicino Airport', 'Rome', 'Italy' );
INSERT INTO airports  (airport_code,airport_name,airport_city,airport_country) VALUES 
					  ('PRG', 'Vaclav Havel Airport Prague', 'Prague', 'Czech Republic' );
INSERT INTO airports  (airport_code,airport_name,airport_city,airport_country) VALUES 
					  ('BUD', 'Budapest Ferenc Liszt International Airport', 'Budapest', 'Hungary' );
INSERT INTO airports  (airport_code,airport_name,airport_city,airport_country) VALUES 
					  ('ZAG', 'Franjo Tudman Airport', 'Zagreb', 'Croatia (Hrvatska)' );
INSERT INTO airports  (airport_code,airport_name,airport_city,airport_country) VALUES 
					  ('GDN', 'Gdansk Lech Walesa Airport', 'Gdañsk', 'Poland' );
INSERT INTO airports  (airport_code,airport_name,airport_city,airport_country) VALUES 
					  ('POZ', 'Poznañ-£awica Henryk Wieniawski Airport', 'Je¿yce', 'Poland' );
INSERT INTO airports  (airport_code,airport_name,airport_city,airport_country) VALUES 
					  ('SZZ', 'Solidarity Szczecin-Goleniów Airport', 'Goleniów', 'Poland' );

COMMIT;
