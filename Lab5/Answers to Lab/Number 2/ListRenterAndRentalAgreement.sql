SELECT R.renter_id, R.first_name, R.middle_initial, R.last_name, R.address, R.city, R.postal_code, R.tel_no, RA.rental_start_date, RA.rental_end_date, RA.weekly_rental_amount, RA.rental_period_weeks
FROM Renter AS R, RentalAgreements as RA
INNER JOIN Property ON R.renter_id = Property.renter_id
INNER JOIN RentalAgreements ON Property.condo_id = RentalAgreements.condo_no;
