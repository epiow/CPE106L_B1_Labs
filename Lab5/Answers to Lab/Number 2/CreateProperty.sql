CREATE TABLE "Property" (
	"condo_id"	INTEGER NOT NULL,
	"renter_id"	INTEGER NOT NULL,
	"condo_location"	TEXT NOT NULL,
	"address"	TEXT NOT NULL,
	"city"	TEXT NOT NULL,
	"state"	TEXT NOT NULL,
	"max_occupancy"	INTEGER NOT NULL,
	"weekly_rate_base"	NUMERIC NOT NULL,
	PRIMARY KEY("condo_id" AUTOINCREMENT),
	FOREIGN KEY("renter_id") REFERENCES "Renter"("renter_id")
)