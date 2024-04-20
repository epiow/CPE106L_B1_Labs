CREATE TABLE "RentalAgreements" (
	"rental_agreement_id"	INTEGER NOT NULL,
	"condo_no"	INTEGER NOT NULL,
	"rental_start_date"	TEXT NOT NULL,
	"rental_end_date"	TEXT NOT NULL,
	"weekly_rental_amount"	NUMERIC NOT NULL,
	"rental_period_weeks"	INTEGER NOT NULL,
	FOREIGN KEY("condo_no") REFERENCES "Property",
	PRIMARY KEY("rental_agreement_id" AUTOINCREMENT)
)