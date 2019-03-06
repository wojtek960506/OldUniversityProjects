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