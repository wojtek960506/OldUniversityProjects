--$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$--
--$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$--
--$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$--

--inserting countries into countries

DELETE FROM countries;

DROP SEQUENCE countries_seq;
CREATE SEQUENCE countries_seq START WITH 1 INCREMENT BY 1 MAXVALUE 246;

DELETE FROM countries;

INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('AF', 'Afghanistan' );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('AL', 'Albania'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('DZ', 'Algeria'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('DS', 'American Samoa'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('AD', 'Andorra'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('AO', 'Angola'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('AI', 'Anguilla'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('AQ', 'Antarctica'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('AG', 'Antigua and Barbuda'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('AR', 'Argentina'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('AM', 'Armenia'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('AW', 'Aruba'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('AU', 'Australia'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('AT', 'Austria'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('AZ', 'Azerbaijan'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('BS', 'Bahamas'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('BH', 'Bahrain'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('BD', 'Bangladesh'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('BB', 'Barbados'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('BY', 'Belarus'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('BE', 'Belgium'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('BZ', 'Belize'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('BJ', 'Benin'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('BM', 'Bermuda'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('BT', 'Bhutan'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('BO', 'Bolivia'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('BA', 'Bosnia and Herzegovina'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('BW', 'Botswana'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('BV', 'Bouvet Island'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('BR', 'Brazil'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('IO', 'British Indian Ocean Territory'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('BN', 'Brunei Darussalam'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('BG', 'Bulgaria'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('BF', 'Burkina Faso'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('BI', 'Burundi'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('KH', 'Cambodia'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('CM', 'Cameroon'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('CA', 'Canada'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('CV', 'Cape Verde'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('KY', 'Cayman Islands'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('CF', 'Central African Republic'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('TD', 'Chad'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('CL', 'Chile'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('CN', 'China'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('CX', 'Christmas Island'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('CC', 'Cocos (Keeling) Islands'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('CO', 'Colombia'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('KM', 'Comoros'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('CG', 'Congo'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('CK', 'Cook Islands'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('CR', 'Costa Rica'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('HR', 'Croatia (Hrvatska)'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('CU', 'Cuba'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('CY', 'Cyprus'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('CZ', 'Czech Republic'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('DK', 'Denmark'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('DJ', 'Djibouti'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('DM', 'Dominica'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('DO', 'Dominican Republic'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('TP', 'East Timor'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('EC', 'Ecuador'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('EG', 'Egypt'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('SV', 'El Salvador'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('GQ', 'Equatorial Guinea'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('ER', 'Eritrea'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('EE', 'Estonia'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('ET', 'Ethiopia'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('FK', 'Falkland Islands (Malvinas)'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('FO', 'Faroe Islands'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('FJ', 'Fiji'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('FI', 'Finland'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('FR', 'France'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('FX', 'France, Metropolitan'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('GF', 'French Guiana'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('PF', 'French Polynesia'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('TF', 'French Southern Territories'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('GA', 'Gabon'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('GM', 'Gambia'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('GE', 'Georgia'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('DE', 'Germany'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('GH', 'Ghana'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('GI', 'Gibraltar'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('GK', 'Guernsey'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('GR', 'Greece'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('GL', 'Greenland'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('GD', 'Grenada'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('GP', 'Guadeloupe'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('GU', 'Guam'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('GT', 'Guatemala'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('GN', 'Guinea'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('GW', 'Guinea-Bissau'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('GY', 'Guyana'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('HT', 'Haiti'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('HM', 'Heard and Mc Donald Islands'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('HN', 'Honduras'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('HK', 'Hong Kong'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('HU', 'Hungary'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('IS', 'Iceland'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('IN', 'India'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('IM', 'Isle of Man'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('ID', 'Indonesia'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('IR', 'Iran (Islamic Republic of)'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('IQ', 'Iraq'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('IE', 'Ireland'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('IL', 'Israel'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('IT', 'Italy'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('CI', 'Ivory Coast'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('JE', 'Jersey'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('JM', 'Jamaica'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('JP', 'Japan'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('JO', 'Jordan'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('KZ', 'Kazakhstan'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('KE', 'Kenya'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('KI', 'Kiribati'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('KP', 'Korea, Democratic People''s Republic of'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('KR', 'Korea, Republic of'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('XK', 'Kosovo'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('KW', 'Kuwait'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('KG', 'Kyrgyzstan'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('LA', 'Lao People''s Democratic Republic'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('LV', 'Latvia'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('LB', 'Lebanon'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('LS', 'Lesotho'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('LR', 'Liberia'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('LY', 'Libyan Arab Jamahiriya'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('LI', 'Liechtenstein'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('LT', 'Lithuania'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('LU', 'Luxembourg'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('MO', 'Macau'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('MK', 'Macedonia'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('MG', 'Madagascar'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('MW', 'Malawi'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('MY', 'Malaysia'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('MV', 'Maldives'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('ML', 'Mali'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('MT', 'Malta'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('MH', 'Marshall Islands'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('MQ', 'Martinique'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('MR', 'Mauritania'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('MU', 'Mauritius'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('TY', 'Mayotte'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('MX', 'Mexico'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('FM', 'Micronesia, Federated States of'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('MD', 'Moldova, Republic of'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('MC', 'Monaco'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('MN', 'Mongolia'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('ME', 'Montenegro'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('MS', 'Montserrat'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('MA', 'Morocco'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('MZ', 'Mozambique'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('MM', 'Myanmar'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('NA', 'Namibia'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('NR', 'Nauru'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('NP', 'Nepal'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('NL', 'Netherlands'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('AN', 'Netherlands Antilles'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('NC', 'New Caledonia'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('NZ', 'New Zealand'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('NI', 'Nicaragua'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('NE', 'Niger'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('NG', 'Nigeria'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('NU', 'Niue'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('NF', 'Norfolk Island'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('MP', 'Northern Mariana Islands'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('NO', 'Norway'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('OM', 'Oman'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('PK', 'Pakistan'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('PW', 'Palau'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('PS', 'Palestine'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('PA', 'Panama'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('PG', 'Papua New Guinea'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('PY', 'Paraguay'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('PE', 'Peru'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('PH', 'Philippines'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('PN', 'Pitcairn'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('PL', 'Poland'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('PT', 'Portugal'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('PR', 'Puerto Rico'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('QA', 'Qatar'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('RE', 'Reunion'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('RO', 'Romania'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('RU', 'Russian Federation'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('RW', 'Rwanda'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('KN', 'Saint Kitts and Nevis'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('LC', 'Saint Lucia'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('VC', 'Saint Vincent and the Grenadines'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('WS', 'Samoa'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('SM', 'San Marino'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('ST', 'Sao Tome and Principe'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('SA', 'Saudi Arabia'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('SN', 'Senegal'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('RS', 'Serbia'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('SC', 'Seychelles'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('SL', 'Sierra Leone'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('SG', 'Singapore'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('SK', 'Slovakia'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('SI', 'Slovenia'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('SB', 'Solomon Islands'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('SO', 'Somalia'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('ZA', 'South Africa'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('GS', 'South Georgia South Sandwich Islands'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('ES', 'Spain'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('LK', 'Sri Lanka'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('SH', 'St. Helena'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('PM', 'St. Pierre and Miquelon'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('SD', 'Sudan'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('SR', 'Suriname'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('SJ', 'Svalbard and Jan Mayen Islands'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('SZ', 'Swaziland'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('SE', 'Sweden'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('CH', 'Switzerland'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('SY', 'Syrian Arab Republic'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('TW', 'Taiwan'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('TJ', 'Tajikistan'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('TZ', 'Tanzania, United Republic of'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('TH', 'Thailand'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('TG', 'Togo'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('TK', 'Tokelau'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('TO', 'Tonga'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('TT', 'Trinidad and Tobago'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('TN', 'Tunisia'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('TR', 'Turkey'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('TM', 'Turkmenistan'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('TC', 'Turks and Caicos Islands'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('TV', 'Tuvalu'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('UG', 'Uganda'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('UA', 'Ukraine'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('AE', 'United Arab Emirates'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('GB', 'United Kingdom'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('US', 'United States'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('UM', 'United States minor outlying islands'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('UY', 'Uruguay'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('UZ', 'Uzbekistan'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('VU', 'Vanuatu'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('VA', 'Vatican City State'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('VE', 'Venezuela'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('VN', 'Vietnam'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('VG', 'Virgin Islands (British)'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('VI', 'Virgin Islands (U.S.)'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('WF', 'Wallis and Futuna Islands'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('EH', 'Western Sahara'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('YE', 'Yemen'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('ZR', 'Zaire'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('ZM', 'Zambia'  );
INSERT INTO COUNTRIES  (country_abbreviation,country_name) VALUES ('ZW', 'Zimbabwe'  );

COMMIT;

--$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$--
--$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$--
--$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$--

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

--$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$--
--$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$--
--$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$--

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

--$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$--
--$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$--
--$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$--

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

--$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$--
--$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$--
--$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$--

--Insert tourists
set serveroutput on format wrapped;
set define off;

DELETE FROM tourists;

DROP SEQUENCE tourists_seq;
CREATE SEQUENCE tourists_seq START WITH 1 INCREMENT BY 1 NOMAXVALUE;

DECLARE
    TYPE TAB_FIRST_NAME_M IS TABLE OF VARCHAR2(20);
    first_name_m TAB_FIRST_NAME_M;
    TYPE TAB_FIRST_NAME_W IS TABLE OF VARCHAR2(20);
    first_name_w TAB_FIRST_NAME_W;
    TYPE TAB_LAST_NAME IS TABLE OF VARCHAR2(20);
    last_name TAB_LAST_NAME;
    
    c_id_min INTEGER;
    c_id_max INTEGER;
    
    fnm NUMBER(5);
    fnw NUMBER(5);
    lnm NUMBER(5);
    lnw NUMBER(5);
    cm NUMBER(5);
    cw NUMBER(5);

BEGIN
    SELECT MIN(country_id) INTO c_id_min from countries;
    SELECT MAX(country_id) INTO c_id_max from countries;

    first_name_m := TAB_FIRST_NAME_M (  'Jan', 'Stanis³aw', 'Andrzej', 'Józef', 'Tadeusz', 'Jerzy', 'Zbigniew', 'Krzysztof', 'Henryk', 
                                        'Ryszard', 'Kazimierz', 'Marek', 'Marian', 'Piotr', 'Janusz', 'W³adys³aw', 'Adam', 'Wies³aw', 
                                        'Zdzis³aw', 'Edward', 'Mieczys³aw', 'Roman', 'Miros³aw', 'Grzegorz', 'Czes³aw', 'Dariusz', 
                                        'Wojciech', 'Jacek', 'Eugeniusz', 'Tomasz', 'Stefan', 'Zygmunt', 'Leszek', 'Bogdan', 'Antoni', 
                                        'Pawe³', 'Franciszek', 'S³awomir', 'Waldemar', 'Jaros³aw', 'Robert', 'Mariusz', 'W³odzimierz', 
                                        'Micha³½', 'Zenon', 'Bogus³aw', 'Witold', 'Aleksander', 'Bronis³aw', 'Wac³aw', 'Boles³aw', 
                                        'Ireneusz', 'Maciej', 'Artur', 'Edmund', 'Marcin', 'Lech', 'Karol', 'Rafa³', 'Arkadiusz', 'Leon', 
                                        'Sylwester', 'Lucjan', 'Julian', 'Wiktor', 'Romuald', 'Bernard', 'Ludwik', 'Feliks', 'Alfred', 
                                        'Alojzy', 'Przemys³aw', 'Cezary', 'Daniel', 'Miko³aj', 'Ignacy', 'Les³aw', 'Rados³aw', 'Konrad', 
                                        'Bogumi³½', 'Szczepan', 'Gerard', 'Hieronim', 'Krystian', 'Leonard', 'Wincenty', 'Benedykt', 
                                        'Hubert', 'Sebastian', 'Norbert', 'Adolf', '£ukasz', 'Emil', 'Teodor', 'Rudolf', 'Joachim', 'Jakub',
                                        'Walenty', 'Alfons', 'Damian', 'Rajmund', 'Szymon', 'Zygfryd','Leopold', 'Remigiusz', 'Florian', 
                                        'Konstanty', 'Augustyn', 'Albin', 'Bohdan', 'Dominik', 'Gabriel', 'Teofil', 'Brunon', 
                                        'Juliusz', 'Walerian', 'Bart³omiej', 'Fryderyk', 'Eryk', 'Anatol', 'Maksymilian', 'Gustaw', 
                                        'Aleksy', 'Longin', 'Bartosz', 'Wilhelm', 'Ferdynand', 'Erwin', 'Klemens', 'Lechos³aw', 'Ernest', 
                                        'Seweryn', 'Herbert', 'Albert', 'B³a¿ej', 'Izydor', 'Dionizy', 'Edwin', 'Ginter', 'Adrian', 'Mateusz',
                                        'Walter', 'Helmut', 'Bazyli', 'Marceli', 'Sergiusz', 'Bonifacy', 'Werner', 'Eligiusz', 'Wawrzyniec');
                                        
    first_name_w := TAB_FIRST_NAME_W (  'Maria', 'Krystyna', 'Anna', 'Barbara', 'Teresa', 'El¿bieta', 'Janina', 'Zofia', 'Jadwiga', 'Danuta', 
                                        'Halina', 'Irena', 'Ewa', 'Ma³gorzata', 'Helena', 'Gra¿yna', 'Bo¿ena', 'Stanis³awa', 'Jolanta', 'Marianna', 
                                        'Urszula', 'Wanda', 'Alicja', 'Dorota', 'Agnieszka', 'Beata', 'Katarzyna', 'Joanna', 'Wies³awa', 'Renata', 
                                        'Iwona', 'Genowefa', 'Kazimiera', 'Stefania', 'Hanna', 'Lucyna', 'Józefa', 'Alina', 'Miros³awa', 'Aleksandra', 
                                        'W³adys³awa', 'Henryka', 'Czes³awa', 'Lidia', 'Regina', 'Monika', 'Magdalena', 'Bogumi³a', 'Marta', 'Marzena', 
                                        'Leokadia', 'Mariola', 'Bronis³awa', 'Aniela', 'Bogus³awa', 'Eugenia', 'Izabela', 'Cecylia', 'Emilia', '£ucja', 
                                        'Gabriela', 'Sabina', 'Zdzis³awa', 'Agata', 'Edyta', 'Aneta', 'Daniela', 'Wioletta', 'Sylwia', 'Weronika', 
                                        'Antonina', 'Justyna', 'Gertruda', 'Mieczys³awa', 'Franciszka', 'Rozalia', 'Zuzanna', 'Natalia', 'Celina', 
                                        'Ilona', 'Alfreda', 'Wiktoria', 'Olga', 'Wac³awa', 'Ró¿a', 'Karolina', 'Bernadeta', 'Julia', 'Michalina', 
                                        'Adela', 'Ludwika', 'Honorata', 'Aldona', 'Eleonora', 'Violetta', 'Felicja', 'Walentyna', 'Pelagia', 
                                        'Apolonia', 'Brygida', 'Zenona', 'Izabella', 'Romana', 'Zenobia', 'Waleria', 'Anita', 'Bo¿enna', 'Romualda',
                                        'Marzanna', 'Anastazja', 'Kamila', 'Aurelia', 'Ewelina', 'Ludmi³a', 'Hildegarda', 'Teodozja', 'Feliksa', 
                                        'Nina', 'Paulina', 'Longina', 'Julianna', 'Klara', 'Marlena', 'Teodora', 'Leonarda', 'Ryszarda', 'Liliana', 
                                        'Kinga', 'Lilianna', 'Albina', 'Elwira', 'Gizela', 'Boles³awa', 'Otylia', 'Karina', 'Arleta', 'Marzenna', 
                                        'Melania', 'Kornelia', 'Salomea', 'Adelajda', 'Eryka', 'Dominika', 'S³awomira', 'Donata', 'Eliza', 'Tamara', 
                                        'Zyta', 'Bernadetta', 'Nadzieja');
                                        
    last_name := TAB_LAST_NAME (        'Zieliñski', 'Rogalski', 'Binkiewicz', 'Pawlak', 'Kowalski', 'Stawiarski', 'Borowicz', 'Talarowski', 'Wójcik', 
                                        'Palmowski', 'Sidor', 'Kowalczyk', 'Górski', 'Kowalski', 'Wisniewski', 'Kowalczyk', 'Kamiñski', 'Lewandowski', 
                                        'Szymañski', 'WoŸniak', 'Jankowski', 'Mazur', 'Wojciechowski', 'Kwiatkowski', 'Krawczyk', 'Kaczmarek', 'Piotrowski', 
                                        'Grabowski', 'Nowakowski', 'Wieczorek', 'Wróbel', 'Dudek', 'Adamczyk', 'Majewski', 'Nowicki', 'Olszewski', 'Malinowski',
                                        'Pawlak', 'Witkowski', 'Walczak', 'Sikora', 'Rutkowski', 'Baran', 'Michalak', 'Szewczyk', 'Ostrowski', 'Tomaszewski', 
                                        'Szewczyk', 'Ostrowski', 'Majewski', 'Tarasiuk', 'Katarzyñski', 'Jachimowski', 'Ludwig', 'Sk³odowski', 'Szopiñski', 'Zubek', 
                                        '£yszczarz', 'Bernat', 'Pietrucha', 'Targosz', 'Weso³ek', 'Brych', 'W¹sowicz', 'Dankowski', '£abêcki', 'Wróbel', 'Rojek', 
                                        'Lenart', 'Ziêba', 'Kotarba', 'Grzyb', 'Pa³ka', 'Maækiewicz', 'Bazan', 'Kwaœny', 'Burski', 'Puk', 'Nowocieñ', 'Koryciñski', 
                                        'Kap³on', 'Tomczak', 'Maciaszczyk', 'Pêczek', 'Pliszka', 'Szypu³a', 'Dygas', 'Borys', 'Wojtkiewicz', 'Konefa³', 'Pindel', 
                                        'Karolak', 'Styczyñski', 'Szczotka', 'Lewandowski', 'Maci¹g', 'Juchniewicz', 'Kurzawa', 'Dzier¿anowski', 'Klepacz', 
                                        'Prokopowicz', 'Gnatowski', 'Matuszewski', 'Parzych', 'Nowek', 'Kuœ', 'Myœliñski', 'Ferenc', 'Bera', 'Rudzki', 'Zdunek', 
                                        'Kruczkowski', 'Sobczuk', 'Wyka', 'Szkudlarek', 'Boratyñski', 'Ko¿uch', 'Szot', 'Babik', 'Tylkowski', 'Meller', 'S³aby', 
                                        'Niemczyk', 'Jarmo³owicz', 'Makuch', 'Œwierczek', 'Stefanek', 'Brzostek', 'Kusy', 'Zbroja', 'Depa', 'Kmiecik', 'Musio³', 
                                        'Bolesta', 'Sobczyk', 'Kozie³', 'Pamu³a', 'Milewski', 'Kaniowski', 'Dziedzic', 'O¿arowski', 'M³ynarski', 'Szul', 'Lubañski', 
                                        'G³ogowski', 'Che³miñski', 'Pelczar', 'Krzemiñski', 'Opoka', 'Klima', 'Majchrzyk', 'Szumilas', 'Hoffmann', 'Perliñski', 
                                        'Adamczuk', 'Potempa', 'Micha³ek', 'Pietruczuk', 'Walkowicz', 'Kosek', 'Przepiórka', 'Kolenda', 'Dobosz', 'Tomaszewicz', 
                                        'Rychel', 'Orszulak', 'Czapliñski', 'Klimaszewski', 'R¹czkowski', '¯uraw', 'Krych', 'M³yñski', 'Mazgaj', 'Podbielski', 
                                        'Jurczyk', 'Dworakowski', 'Pawlus', 'Kosicki', 'Urbanek', 'Fr¹czek', 'Zagórski', 'Rosó³', 'Gac', 'Synowiec', 'Garbowski', 
                                        'Gontarz', 'Szuster', 'Ró¿ycki', 'Kmieciak', 'Berliñski', 'Zwierzchowski', 'Dyjak', 'Wieliczko', 'Kêsy', 'Koba', 'Trzaski', 
                                        '£abuda', 'Kozik', 'Orczyk', 'Moczulski', 'Bala', 'Linek', 'Dubas', 'Sobkowiak', 'Zychowicz', 'Dominiczak', 'Ciechomski', 
                                        'Rojewski', 'Sulewski', 'Ryszkowski', 'Mrozek', 'Pucek', 'Cyganek', 'Cieœlak', 'Piekut', 'Œl¹zak', 'KaŸmierczak', 'Krynicki', 
                                        'Wantuch', 'Andruszkiewicz', 'Tymiñski', 'Seroczyñski', 'Fiedorowicz', 'Nita', 'Kozakiewicz', 'Waœko', 'Filipski', 'KoŸmiñski', 
                                        'Izydorczyk', '£yczko', 'Ca³a', 'Stolc', 'Stolarski', 'Matulewicz', 'Modliñski', 'Staszczyk', 'Jaroszyñski', 'Sajdak', 'Rybka', 
                                        'Ga³kowski', 'Narloch', 'Bodnar', 'Wieczorek', 'Raczek', 'Miszczuk', 'Ksiê¿opolski', 'M¹czyñski', 'Klasa', 'P¹czek', 'Lenarczyk', 
                                        'Olszañski', 'Sas', 'Tracz', 'Greñ', 'Szczyrba', 'Marchlewski', 'Maciaszek', 'K³os', 'Jaskot', 'Ceglarski', 'Zoñ', 'Nitka', 
                                        'Pêkalski', 'Golis', 'Knopik', 'Dro¿d¿', 'Waœkiewicz', 'Jaruga', 'Pawiñski', 'Kraœnicki', 'Laski', 'Kiedrowski', 'Cieœluk', 
                                        'Wolf', 'Krysa', 'Czeka³a', 'Mierzwa', 'Wala', 'Dolny', 'Bartosik', 'Sobala', 'Chrapek', 'Strach', 'Niedzielski', 'Sierocki', 
                                        'Kura', 'Baj', 'Czy¿yk', 'Lupa', 'Panas', 'Malicki', 'Bobiñski', 'Idziak', 'Kochanek', 'Iwaszko', 'Grenda', 'Paluszek', 
                                        'Zborowski', 'Karolczyk', 'Ziemba', 'Florczak', 'Kurzak', 'Tobo³a', 'Dembowski', 'Klusek', 'Wilga', 'Kudliñski', 'Ko³ecki', 
                                        'Kêdzior', 'Rosik', 'Buga³a', 'Witkowski', 'NiedŸwiedŸ', 'Grzeœ', 'Bojarski', 'Wasilewski', 'Szczygielski', 'Gorczyñski', 
                                        'Filipiuk', 'Ceg³owski', 'Chmielewski', 'Wo³owiec', 'Kozio³ek', 'Korzeniowski', 'Noga', 'K³ak', 'Orliñski', 'Krzeœniak', 
                                        'Przygoda', 'Witczak', 'Pawlas', 'Ratajczak', 'Konieczna', 'Dêbkowski', 'Lewandowicz', 'Treder', 'Borowczak', 'Gajda', 'Gaj', 
                                        'Borowiak', 'Pajewski', 'Anio³', 'Starczewski', 'Kozanecki', 'Boczar', 'Paœ', 'Grêda', 'Goœciniak', 'Gawron', 'Kwapisz', 'Soboñ', 
                                        'Koby³ecki', 'Zawada', 'Kubik', 'Maliñski', 'Jamka', 'Bartoszuk', 'Kryszak', 'Wojdy³o', 'Pra³at', 'Modzelewski', 'Bator', 'Borucki', 
                                        'Bogdañski', 'Zduniak', 'Talar', 'Kanclerz', 'Kurkowski', 'GoŸdzik', 'Ozimek', 'Marcinkowski', 'Jagodziñski', 'Deska', 'Chojecki', 
                                        'Koliñski', 'S³owiñski', 'Suchan', 'Ko³odziejski', 'Tokarski', 'O³dak', 'Chmieliñski', 'Pyra', 'Chmielowski', 'WoŸniak', 'Filipczak', 
                                        'Soszka', 'Kobylañski', 'Szulik', 'Biskupski', 'Okoniewski', 'Kêski', 'Roman', 'Korona', 'Guba³a', 'Surmacz', 'Mo¿d¿eñ', 'Gralak', 
                                        'Zaleski', '¯urowski', 'Ka³a', 'Bogdanowicz', 'Klimkiewicz', 'Kopeæ', 'Bartosz', 'Pisarczyk', 'Hawryluk', 'Wolnik', 'Rakoczy', 
                                        'Otto', 'Wiecha', 'Latawiec', 'Koperski', 'Krzysiek', 'Binek', 'Przytu³a', 'Nowok', 'Sawczuk', 'Golik', 'Janiczek', 'Przerwa', 
                                        'Rosiñski', 'Werner', 'Guzek', 'B³asiak', 'W³odarek', 'Karolczak', 'Wieloch', 'Mendyk', 'Kornas', 'Zdanowski', 'Bochenek', 
                                        'Adamczak', 'Przywara', 'Walaszek', 'JóŸwicki', 'Witt', 'Ludwikowski', 'Domagalski', 'Œmia³ek', 'Pieprzyk', 'Pikulski', 'Motyl', 
                                        'Siwak', 'Mrozik', 'Karpiuk', 'Walczyk', 'Go³da', 'Mazur', 'Waœ', 'Walaszczyk', 'Mielnik', 'Czerwonka', 'Dybowski', 'P³awecki', 
                                        'Kobus', 'Marks', 'Karczewski', 'Masternak', 'Sawka', 'Polañski', 'Wojtyczka', 'Maciejewski', 'Kmita', 'Dzida', 'Buka³a', 'Kluz', 
                                        'Lasak', 'Paziewski', 'Sulej', 'Hryniewicz', 'Czarnota', 'Jasiewicz', 'O³dakowski', 'Winnicki', 'B³aszkowski', 'Wojtasiak', 
                                        'Jedliñski', 'Gosk', 'Kluk', 'Ga³czyñski', 'Piechowiak', 'Mocek', 'Ogrodowski', 'Stawski', 'Gierczak', 'Skoczeñ', 'Barabasz', 
                                        'P³achta', 'Popio³ek', 'Sacha', 'Rêkas', 'Barczyk', 'Giziñski', 'Korzeniewski', 'Koch', 'Kluza', 'Papie¿', 'Kokociñski', 'Ossowski', 
                                        'Migda³', 'Gad', 'Skórski', 'S³owik', 'Komar', 'Rak', 'Cisek', 'Syrek', 'Kordek', 'Bauer', 'Sidorowicz', 'Choma', 'Marcinkiewicz', 
                                        'Kwidziñski', 'Przybyszewski', 'Gorczyca', 'Kokot', 'Grabowski', 'Molik', 'Burzyñski', 'Jaskó³ka', 'Krzak', 'Nowosad', '£upiñski', 
                                        'Zió³kowski', 'Pasek', 'Zawistowski', 'Tokarz', 'Babiak', 'Polowczyk', 'Olbryœ', 'Pietruszewski', 'Kuœnierz', 'Gracz', 'Suchomski', 
                                        'Oleœ', 'Gawryluk', 'Ujma', 'Mróz', '£yczkowski', 'JóŸwiak', 'Nikodem', 'Gancarczyk', 'Skóra', 'Palacz', 'Kuc', 'Marczak', 
                                        'Martyniuk', 'Kowalewski', 'Konarzewski', 'Adler');  

    
    FOR i IN 1..1500 LOOP
        fnm := dbms_random.value(1,first_name_m.count); --150
        fnw := dbms_random.value(1,first_name_w.count); --150
        lnm := dbms_random.value(1,last_name.count); --550
        lnw := dbms_random.value(1,last_name.count); --550
        cm := dbms_random.value(c_id_min,c_id_max);
        cw := dbms_random.value(c_id_min,c_id_max);
        
        INSERT INTO tourists (tourist_first_name, tourist_last_name, tourist_country)
        VALUES (first_name_m(fnm), last_name(lnm), ( SELECT country_name FROM countries WHERE country_id = cm ) );
        
        INSERT INTO tourists (tourist_first_name, tourist_last_name, tourist_country   )
        VALUES (first_name_w(fnm), last_name(lnw), ( SELECT country_name FROM countries WHERE country_id = cw ) ); 
    END LOOP;
    
END;
/   

COMMIT;

--$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$--
--$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$--
--$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$--

--insert into reservations

set serveroutput on format wrapped;
set define off;

DELETE FROM reservations;

DROP SEQUENCE reservations_seq;
CREATE SEQUENCE reservations_seq START WITH 1 INCREMENT BY 1 NOMAXVALUE;

DECLARE    
    f_id NUMERIC(4); --flight_id
    f_min_id NUMERIC (4);
    f_max_id NUMERIC (4);
    
    t_id NUMERIC(4); --tourist_id  
    t_count NUMERIC(4); --to randomize tourist id
    t_min_id NUMERIC (4);
    t_max_id NUMERIC (4);
    
    r_id NUMERIC(4); --reservation_id
    r_count INTEGER(4);
    
BEGIN
	FOR i IN 1..100 LOOP 
    
        --SELECT count(*) into t_count from tourists;
        SELECT min(tourist_id) into t_min_id from tourists;
        SELECT MAX(tourist_id) into t_max_id from tourists;
        
        --SELECT min(flight_id) into f_min_id from flights;
        --SELECT MAX(flight_id) into f_max_id from flights;
        
        t_id := dbms_random.value(t_min_id, t_max_id); --random tourist_id
        --f_id := dbms_random.value(f_min_id, f_max_id); --random flight_id

        --r_id := reservations_seq.NEXTVAL;
        
        INSERT INTO reservations ( tourist_id ) VALUES ( t_id);
	END LOOP;
END;
/

commit;

--$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$--
--$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$--
--$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$--

--flights reservations insert

DELETE FROM flights_reservations;
DELETE FROM discounts;
DROP SEQUENCE discounts_seq;
CREATE SEQUENCE discounts_seq START WITH 1 INCREMENT BY 1 NOMAXVALUE;

DECLARE
    --we establish that flights_id and reservations_id are one by one

    r_id NUMERIC(4); --reservation_id
    r_count INTEGER(4); --number of reservations
    f_id NUMERIC(4); --flight_id
    f_min_id NUMERIC (4); --minimum flight_id
    f_max_id NUMERIC (4);
    
BEGIN
    select min(reservation_id) into r_id from reservations;
    select count(*) into r_count from reservations;
    
    FOR i IN r_id..r_count LOOP 
        SELECT min(flight_id) into f_min_id from flights;
        SELECT MAX(flight_id) into f_max_id from flights;
  
        f_id := dbms_random.value(f_min_id, f_max_id); --random flight_id
        INSERT INTO flights_reservations VALUES (f_id,i);
	END LOOP;
END;
/

commit;

--$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$--
--$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$--
--$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$--