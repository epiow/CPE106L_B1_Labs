CREATE TABLE "Renter" (
	"renter_id"	INTEGER NOT NULL,
	"first_name"	TEXT NOT NULL,
	"middle_initial"	TEXT NOT NULL,
	"last_name"	TEXT NOT NULL,
	"address"	TEXT,
	"city"	TEXT NOT NULL,
	"postal_code"	INTEGER NOT NULL,
	"tel_no"	TEXT NOT NULL,
	"email_address"	TEXT NOT NULL CHECK(email_address LIKE '%@%.%'),
	PRIMARY KEY("renter_id" AUTOINCREMENT)
)