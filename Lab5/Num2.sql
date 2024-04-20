--For each participant, list his or her number, last name, first name, address, city, state, postal code, telephone number, and date of birth.
SELECT
    P.participant_id,
    P.last_name,
    P.first_name,
    P.address,
    P.city,
    P.state,
    P.zip_code,
    P.phone,
    P.date_of_birth
FROM Participants as P;
--For each adventure class, list the class number, class description, maximum number of people in the class, and class fee.
SELECT
    C.date, C.class_no,
    C.description, C.max_number, C.fee
FROM AdventureClasses AS C;
-- For each participant, list his or her number, first name, and the class number, class descripton, and the date of the class for each class in which the participant is enrolled
SELECT
    P.participant_id,
    P.first_name,
    C.class_no,
    C.description,
    C.date
FROM Participants AS P
    INNER JOIN AdventureClasses as C ON P.participant_id = C.class_no;
-- For each class, list the class date, class number, and class description; and the number, last name and first name of each participant in the class_no

SELECT
    C.date,
    C.class_no,
    C.description,
    P.participant_id,
    P.last_name,
    P.first_name
FROM Participants AS P
    INNER JOIN AdventureClasses AS C
    ON P.participant_id = C.class_no;