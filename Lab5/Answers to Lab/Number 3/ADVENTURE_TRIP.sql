
--A.)
--Creation of the table
CREATE TABLE ADVENTURE_TRIP (
    TRIP_ID INTEGER PRIMARY KEY,
    TRIP_NAME VARCHAR,
    START_LOCATION VARCHAR,
    STATE VARCHAR,
    DISTANCE NUMBER,
    MAX_GRP_SIZE NUMBER,
    TYPE VARCHAR,
    SEASON VARCHAR
);
-- Showing the information of the table
PRAGMA table_info(ADVENTURE_TRIP);

--B.)
-- Insertion of Values on rows
INSERT INTO ADVENTURE_TRIP (TRIP_ID, TRIP_NAME, START_LOCATION, STATE, DISTANCE, MAX_GRP_SIZE, TYPE, SEASON) 
VALUES (45, 'Jay Peak', 'Jay', 'VT', 8, 8, 'Hiking', 'Summer');
-- Viewing of the Table row after insertion.
SELECT * FROM ADVENTURE_TRIP;


--C.)
-- Deleting the table
DROP TABLE IF EXISTS ADVENTURE_TRIP;
