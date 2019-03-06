--Insert airlines

DELETE FROM airlines;

DROP SEQUENCE   airlines_seq;
CREATE SEQUENCE airlines_seq START WITH 1 INCREMENT BY 1 NOMAXVALUE;

INSERT INTO airlines(airline_name,airline_country) VALUES ('TAM Linhas Aereas', 'Brazil' );
INSERT INTO airlines(airline_name,airline_country) VALUES ('Wizz Air', 'Hungary' );
INSERT INTO airlines(airline_name,airline_country) VALUES ('LOT Polish Airlines', 'Poland' );
INSERT INTO airlines(airline_name,airline_country) VALUES ('Swiss International Airlines', 'Switzerland' );
INSERT INTO airlines(airline_name,airline_country) VALUES ('Ryanair', 'Ireland' );
INSERT INTO airlines(airline_name,airline_country) VALUES ('Saudi Arabian Airlines', 'Saudi Arabia' );
INSERT INTO airlines(airline_name,airline_country) VALUES ('Lufthansa', 'Germany' );
INSERT INTO airlines(airline_name,airline_country) VALUES ('British Airways', 'United Kingdom' );
INSERT INTO airlines(airline_name,airline_country) VALUES ('Air France', 'France' );
INSERT INTO airlines(airline_name,airline_country) VALUES ('Turkish Airlines', 'Turkey' );
INSERT INTO airlines(airline_name,airline_country) VALUES ('Brussels Airlines', 'Belgium' );
INSERT INTO airlines(airline_name,airline_country) VALUES ('Croatia Airlines', 'Croatia (Hrvatska)' );
INSERT INTO airlines(airline_name,airline_country) VALUES ('Delta Air Lines', 'United States' );
INSERT INTO airlines(airline_name,airline_country) VALUES ('United Airlines', 'United States' );
INSERT INTO airlines(airline_name,airline_country) VALUES ('Southwest Airlines', 'United States' );
INSERT INTO airlines(airline_name,airline_country) VALUES ('American Airlines', 'United States' );
INSERT INTO airlines(airline_name,airline_country) VALUES ('China Southern Airlines', 'China' );
INSERT INTO airlines(airline_name,airline_country) VALUES ('US Airways', 'United States' );
INSERT INTO airlines(airline_name,airline_country) VALUES ('China Eastern Airlines', 'China' );
INSERT INTO airlines(airline_name,airline_country) VALUES ('KLM', 'Netherlands' );
INSERT INTO airlines(airline_name,airline_country) VALUES ('Air Berlin', 'Germany' );
INSERT INTO airlines(airline_name,airline_country) VALUES ('easyJet', 'United Kingdom' );
INSERT INTO airlines(airline_name,airline_country) VALUES ('Emirates', 'United Arab Emirates' );
INSERT INTO airlines(airline_name,airline_country) VALUES ('Air Canada', 'Canada' );
INSERT INTO airlines(airline_name,airline_country) VALUES ('China Western Airlines', 'China' );
INSERT INTO airlines(airline_name,airline_country) VALUES ('China Northest Airlines', 'China' );
INSERT INTO airlines(airline_name,airline_country) VALUES ('Singapore Airlines', 'Singapore' );
INSERT INTO airlines(airline_name,airline_country) VALUES ('All Nippon Airways', 'Japan' );
INSERT INTO airlines(airline_name,airline_country) VALUES ('EgyptAir', 'Egypt' );
INSERT INTO airlines(airline_name,airline_country) VALUES ('Quantas Group', 'Australia' );
INSERT INTO airlines(airline_name,airline_country) VALUES ('Air Moldova', 'Moldova, Republic of' );
INSERT INTO airlines(airline_name,airline_country) VALUES ('Virgin Atlantic Airways', 'United Kingdom' );

COMMIT;