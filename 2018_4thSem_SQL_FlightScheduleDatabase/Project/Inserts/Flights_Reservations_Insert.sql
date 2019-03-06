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