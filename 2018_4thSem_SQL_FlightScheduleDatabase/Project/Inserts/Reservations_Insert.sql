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
       -- SELECT MAX(flight_id) into f_max_id from flights;
        
        t_id := dbms_random.value(t_min_id, t_max_id); --random tourist_id
        --f_id := dbms_random.value(f_min_id, f_max_id); --random flight_id

        --r_id := reservations_seq.NEXTVAL;
        
        INSERT INTO reservations ( tourist_id ) VALUES (t_id);
	END LOOP;
END;
/

commit;