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

    first_name_m := TAB_FIRST_NAME_M (  'Jan', 'Stanis�aw', 'Andrzej', 'J�zef', 'Tadeusz', 'Jerzy', 'Zbigniew', 'Krzysztof', 'Henryk', 
                                        'Ryszard', 'Kazimierz', 'Marek', 'Marian', 'Piotr', 'Janusz', 'W�adys�aw', 'Adam', 'Wies�aw', 
                                        'Zdzis�aw', 'Edward', 'Mieczys�aw', 'Roman', 'Miros�aw', 'Grzegorz', 'Czes�aw', 'Dariusz', 
                                        'Wojciech', 'Jacek', 'Eugeniusz', 'Tomasz', 'Stefan', 'Zygmunt', 'Leszek', 'Bogdan', 'Antoni', 
                                        'Pawe�', 'Franciszek', 'S�awomir', 'Waldemar', 'Jaros�aw', 'Robert', 'Mariusz', 'W�odzimierz', 
                                        'Micha��', 'Zenon', 'Bogus�aw', 'Witold', 'Aleksander', 'Bronis�aw', 'Wac�aw', 'Boles�aw', 
                                        'Ireneusz', 'Maciej', 'Artur', 'Edmund', 'Marcin', 'Lech', 'Karol', 'Rafa�', 'Arkadiusz', 'Leon', 
                                        'Sylwester', 'Lucjan', 'Julian', 'Wiktor', 'Romuald', 'Bernard', 'Ludwik', 'Feliks', 'Alfred', 
                                        'Alojzy', 'Przemys�aw', 'Cezary', 'Daniel', 'Miko�aj', 'Ignacy', 'Les�aw', 'Rados�aw', 'Konrad', 
                                        'Bogumi��', 'Szczepan', 'Gerard', 'Hieronim', 'Krystian', 'Leonard', 'Wincenty', 'Benedykt', 
                                        'Hubert', 'Sebastian', 'Norbert', 'Adolf', '�ukasz', 'Emil', 'Teodor', 'Rudolf', 'Joachim', 'Jakub',
                                        'Walenty', 'Alfons', 'Damian', 'Rajmund', 'Szymon', 'Zygfryd','Leopold', 'Remigiusz', 'Florian', 
                                        'Konstanty', 'Augustyn', 'Albin', 'Bohdan', 'Dominik', 'Gabriel', 'Teofil', 'Brunon', 
                                        'Juliusz', 'Walerian', 'Bart�omiej', 'Fryderyk', 'Eryk', 'Anatol', 'Maksymilian', 'Gustaw', 
                                        'Aleksy', 'Longin', 'Bartosz', 'Wilhelm', 'Ferdynand', 'Erwin', 'Klemens', 'Lechos�aw', 'Ernest', 
                                        'Seweryn', 'Herbert', 'Albert', 'B�a�ej', 'Izydor', 'Dionizy', 'Edwin', 'Ginter', 'Adrian', 'Mateusz',
                                        'Walter', 'Helmut', 'Bazyli', 'Marceli', 'Sergiusz', 'Bonifacy', 'Werner', 'Eligiusz', 'Wawrzyniec');
                                        
    first_name_w := TAB_FIRST_NAME_W (  'Maria', 'Krystyna', 'Anna', 'Barbara', 'Teresa', 'El�bieta', 'Janina', 'Zofia', 'Jadwiga', 'Danuta', 
                                        'Halina', 'Irena', 'Ewa', 'Ma�gorzata', 'Helena', 'Gra�yna', 'Bo�ena', 'Stanis�awa', 'Jolanta', 'Marianna', 
                                        'Urszula', 'Wanda', 'Alicja', 'Dorota', 'Agnieszka', 'Beata', 'Katarzyna', 'Joanna', 'Wies�awa', 'Renata', 
                                        'Iwona', 'Genowefa', 'Kazimiera', 'Stefania', 'Hanna', 'Lucyna', 'J�zefa', 'Alina', 'Miros�awa', 'Aleksandra', 
                                        'W�adys�awa', 'Henryka', 'Czes�awa', 'Lidia', 'Regina', 'Monika', 'Magdalena', 'Bogumi�a', 'Marta', 'Marzena', 
                                        'Leokadia', 'Mariola', 'Bronis�awa', 'Aniela', 'Bogus�awa', 'Eugenia', 'Izabela', 'Cecylia', 'Emilia', '�ucja', 
                                        'Gabriela', 'Sabina', 'Zdzis�awa', 'Agata', 'Edyta', 'Aneta', 'Daniela', 'Wioletta', 'Sylwia', 'Weronika', 
                                        'Antonina', 'Justyna', 'Gertruda', 'Mieczys�awa', 'Franciszka', 'Rozalia', 'Zuzanna', 'Natalia', 'Celina', 
                                        'Ilona', 'Alfreda', 'Wiktoria', 'Olga', 'Wac�awa', 'R�a', 'Karolina', 'Bernadeta', 'Julia', 'Michalina', 
                                        'Adela', 'Ludwika', 'Honorata', 'Aldona', 'Eleonora', 'Violetta', 'Felicja', 'Walentyna', 'Pelagia', 
                                        'Apolonia', 'Brygida', 'Zenona', 'Izabella', 'Romana', 'Zenobia', 'Waleria', 'Anita', 'Bo�enna', 'Romualda',
                                        'Marzanna', 'Anastazja', 'Kamila', 'Aurelia', 'Ewelina', 'Ludmi�a', 'Hildegarda', 'Teodozja', 'Feliksa', 
                                        'Nina', 'Paulina', 'Longina', 'Julianna', 'Klara', 'Marlena', 'Teodora', 'Leonarda', 'Ryszarda', 'Liliana', 
                                        'Kinga', 'Lilianna', 'Albina', 'Elwira', 'Gizela', 'Boles�awa', 'Otylia', 'Karina', 'Arleta', 'Marzenna', 
                                        'Melania', 'Kornelia', 'Salomea', 'Adelajda', 'Eryka', 'Dominika', 'S�awomira', 'Donata', 'Eliza', 'Tamara', 
                                        'Zyta', 'Bernadetta', 'Nadzieja');
                                        
    last_name := TAB_LAST_NAME (        'Zieli�ski', 'Rogalski', 'Binkiewicz', 'Pawlak', 'Kowalski', 'Stawiarski', 'Borowicz', 'Talarowski', 'W�jcik', 
                                        'Palmowski', 'Sidor', 'Kowalczyk', 'G�rski', 'Kowalski', 'Wisniewski', 'Kowalczyk', 'Kami�ski', 'Lewandowski', 
                                        'Szyma�ski', 'Wo�niak', 'Jankowski', 'Mazur', 'Wojciechowski', 'Kwiatkowski', 'Krawczyk', 'Kaczmarek', 'Piotrowski', 
                                        'Grabowski', 'Nowakowski', 'Wieczorek', 'Wr�bel', 'Dudek', 'Adamczyk', 'Majewski', 'Nowicki', 'Olszewski', 'Malinowski',
                                        'Pawlak', 'Witkowski', 'Walczak', 'Sikora', 'Rutkowski', 'Baran', 'Michalak', 'Szewczyk', 'Ostrowski', 'Tomaszewski', 
                                        'Szewczyk', 'Ostrowski', 'Majewski', 'Tarasiuk', 'Katarzy�ski', 'Jachimowski', 'Ludwig', 'Sk�odowski', 'Szopi�ski', 'Zubek', 
                                        '�yszczarz', 'Bernat', 'Pietrucha', 'Targosz', 'Weso�ek', 'Brych', 'W�sowicz', 'Dankowski', '�ab�cki', 'Wr�bel', 'Rojek', 
                                        'Lenart', 'Zi�ba', 'Kotarba', 'Grzyb', 'Pa�ka', 'Ma�kiewicz', 'Bazan', 'Kwa�ny', 'Burski', 'Puk', 'Nowocie�', 'Koryci�ski', 
                                        'Kap�on', 'Tomczak', 'Maciaszczyk', 'P�czek', 'Pliszka', 'Szypu�a', 'Dygas', 'Borys', 'Wojtkiewicz', 'Konefa�', 'Pindel', 
                                        'Karolak', 'Styczy�ski', 'Szczotka', 'Lewandowski', 'Maci�g', 'Juchniewicz', 'Kurzawa', 'Dzier�anowski', 'Klepacz', 
                                        'Prokopowicz', 'Gnatowski', 'Matuszewski', 'Parzych', 'Nowek', 'Ku�', 'My�li�ski', 'Ferenc', 'Bera', 'Rudzki', 'Zdunek', 
                                        'Kruczkowski', 'Sobczuk', 'Wyka', 'Szkudlarek', 'Boraty�ski', 'Ko�uch', 'Szot', 'Babik', 'Tylkowski', 'Meller', 'S�aby', 
                                        'Niemczyk', 'Jarmo�owicz', 'Makuch', '�wierczek', 'Stefanek', 'Brzostek', 'Kusy', 'Zbroja', 'Depa', 'Kmiecik', 'Musio�', 
                                        'Bolesta', 'Sobczyk', 'Kozie�', 'Pamu�a', 'Milewski', 'Kaniowski', 'Dziedzic', 'O�arowski', 'M�ynarski', 'Szul', 'Luba�ski', 
                                        'G�ogowski', 'Che�mi�ski', 'Pelczar', 'Krzemi�ski', 'Opoka', 'Klima', 'Majchrzyk', 'Szumilas', 'Hoffmann', 'Perli�ski', 
                                        'Adamczuk', 'Potempa', 'Micha�ek', 'Pietruczuk', 'Walkowicz', 'Kosek', 'Przepi�rka', 'Kolenda', 'Dobosz', 'Tomaszewicz', 
                                        'Rychel', 'Orszulak', 'Czapli�ski', 'Klimaszewski', 'R�czkowski', '�uraw', 'Krych', 'M�y�ski', 'Mazgaj', 'Podbielski', 
                                        'Jurczyk', 'Dworakowski', 'Pawlus', 'Kosicki', 'Urbanek', 'Fr�czek', 'Zag�rski', 'Ros�', 'Gac', 'Synowiec', 'Garbowski', 
                                        'Gontarz', 'Szuster', 'R�ycki', 'Kmieciak', 'Berli�ski', 'Zwierzchowski', 'Dyjak', 'Wieliczko', 'K�sy', 'Koba', 'Trzaski', 
                                        '�abuda', 'Kozik', 'Orczyk', 'Moczulski', 'Bala', 'Linek', 'Dubas', 'Sobkowiak', 'Zychowicz', 'Dominiczak', 'Ciechomski', 
                                        'Rojewski', 'Sulewski', 'Ryszkowski', 'Mrozek', 'Pucek', 'Cyganek', 'Cie�lak', 'Piekut', '�l�zak', 'Ka�mierczak', 'Krynicki', 
                                        'Wantuch', 'Andruszkiewicz', 'Tymi�ski', 'Seroczy�ski', 'Fiedorowicz', 'Nita', 'Kozakiewicz', 'Wa�ko', 'Filipski', 'Ko�mi�ski', 
                                        'Izydorczyk', '�yczko', 'Ca�a', 'Stolc', 'Stolarski', 'Matulewicz', 'Modli�ski', 'Staszczyk', 'Jaroszy�ski', 'Sajdak', 'Rybka', 
                                        'Ga�kowski', 'Narloch', 'Bodnar', 'Wieczorek', 'Raczek', 'Miszczuk', 'Ksi�opolski', 'M�czy�ski', 'Klasa', 'P�czek', 'Lenarczyk', 
                                        'Olsza�ski', 'Sas', 'Tracz', 'Gre�', 'Szczyrba', 'Marchlewski', 'Maciaszek', 'K�os', 'Jaskot', 'Ceglarski', 'Zo�', 'Nitka', 
                                        'P�kalski', 'Golis', 'Knopik', 'Dro�d�', 'Wa�kiewicz', 'Jaruga', 'Pawi�ski', 'Kra�nicki', 'Laski', 'Kiedrowski', 'Cie�luk', 
                                        'Wolf', 'Krysa', 'Czeka�a', 'Mierzwa', 'Wala', 'Dolny', 'Bartosik', 'Sobala', 'Chrapek', 'Strach', 'Niedzielski', 'Sierocki', 
                                        'Kura', 'Baj', 'Czy�yk', 'Lupa', 'Panas', 'Malicki', 'Bobi�ski', 'Idziak', 'Kochanek', 'Iwaszko', 'Grenda', 'Paluszek', 
                                        'Zborowski', 'Karolczyk', 'Ziemba', 'Florczak', 'Kurzak', 'Tobo�a', 'Dembowski', 'Klusek', 'Wilga', 'Kudli�ski', 'Ko�ecki', 
                                        'K�dzior', 'Rosik', 'Buga�a', 'Witkowski', 'Nied�wied�', 'Grze�', 'Bojarski', 'Wasilewski', 'Szczygielski', 'Gorczy�ski', 
                                        'Filipiuk', 'Ceg�owski', 'Chmielewski', 'Wo�owiec', 'Kozio�ek', 'Korzeniowski', 'Noga', 'K�ak', 'Orli�ski', 'Krze�niak', 
                                        'Przygoda', 'Witczak', 'Pawlas', 'Ratajczak', 'Konieczna', 'D�bkowski', 'Lewandowicz', 'Treder', 'Borowczak', 'Gajda', 'Gaj', 
                                        'Borowiak', 'Pajewski', 'Anio�', 'Starczewski', 'Kozanecki', 'Boczar', 'Pa�', 'Gr�da', 'Go�ciniak', 'Gawron', 'Kwapisz', 'Sobo�', 
                                        'Koby�ecki', 'Zawada', 'Kubik', 'Mali�ski', 'Jamka', 'Bartoszuk', 'Kryszak', 'Wojdy�o', 'Pra�at', 'Modzelewski', 'Bator', 'Borucki', 
                                        'Bogda�ski', 'Zduniak', 'Talar', 'Kanclerz', 'Kurkowski', 'Go�dzik', 'Ozimek', 'Marcinkowski', 'Jagodzi�ski', 'Deska', 'Chojecki', 
                                        'Koli�ski', 'S�owi�ski', 'Suchan', 'Ko�odziejski', 'Tokarski', 'O�dak', 'Chmieli�ski', 'Pyra', 'Chmielowski', 'Wo�niak', 'Filipczak', 
                                        'Soszka', 'Kobyla�ski', 'Szulik', 'Biskupski', 'Okoniewski', 'K�ski', 'Roman', 'Korona', 'Guba�a', 'Surmacz', 'Mo�d�e�', 'Gralak', 
                                        'Zaleski', '�urowski', 'Ka�a', 'Bogdanowicz', 'Klimkiewicz', 'Kope�', 'Bartosz', 'Pisarczyk', 'Hawryluk', 'Wolnik', 'Rakoczy', 
                                        'Otto', 'Wiecha', 'Latawiec', 'Koperski', 'Krzysiek', 'Binek', 'Przytu�a', 'Nowok', 'Sawczuk', 'Golik', 'Janiczek', 'Przerwa', 
                                        'Rosi�ski', 'Werner', 'Guzek', 'B�asiak', 'W�odarek', 'Karolczak', 'Wieloch', 'Mendyk', 'Kornas', 'Zdanowski', 'Bochenek', 
                                        'Adamczak', 'Przywara', 'Walaszek', 'J�wicki', 'Witt', 'Ludwikowski', 'Domagalski', '�mia�ek', 'Pieprzyk', 'Pikulski', 'Motyl', 
                                        'Siwak', 'Mrozik', 'Karpiuk', 'Walczyk', 'Go�da', 'Mazur', 'Wa�', 'Walaszczyk', 'Mielnik', 'Czerwonka', 'Dybowski', 'P�awecki', 
                                        'Kobus', 'Marks', 'Karczewski', 'Masternak', 'Sawka', 'Pola�ski', 'Wojtyczka', 'Maciejewski', 'Kmita', 'Dzida', 'Buka�a', 'Kluz', 
                                        'Lasak', 'Paziewski', 'Sulej', 'Hryniewicz', 'Czarnota', 'Jasiewicz', 'O�dakowski', 'Winnicki', 'B�aszkowski', 'Wojtasiak', 
                                        'Jedli�ski', 'Gosk', 'Kluk', 'Ga�czy�ski', 'Piechowiak', 'Mocek', 'Ogrodowski', 'Stawski', 'Gierczak', 'Skocze�', 'Barabasz', 
                                        'P�achta', 'Popio�ek', 'Sacha', 'R�kas', 'Barczyk', 'Gizi�ski', 'Korzeniewski', 'Koch', 'Kluza', 'Papie�', 'Kokoci�ski', 'Ossowski', 
                                        'Migda�', 'Gad', 'Sk�rski', 'S�owik', 'Komar', 'Rak', 'Cisek', 'Syrek', 'Kordek', 'Bauer', 'Sidorowicz', 'Choma', 'Marcinkiewicz', 
                                        'Kwidzi�ski', 'Przybyszewski', 'Gorczyca', 'Kokot', 'Grabowski', 'Molik', 'Burzy�ski', 'Jask�ka', 'Krzak', 'Nowosad', '�upi�ski', 
                                        'Zi�kowski', 'Pasek', 'Zawistowski', 'Tokarz', 'Babiak', 'Polowczyk', 'Olbry�', 'Pietruszewski', 'Ku�nierz', 'Gracz', 'Suchomski', 
                                        'Ole�', 'Gawryluk', 'Ujma', 'Mr�z', '�yczkowski', 'J�wiak', 'Nikodem', 'Gancarczyk', 'Sk�ra', 'Palacz', 'Kuc', 'Marczak', 
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