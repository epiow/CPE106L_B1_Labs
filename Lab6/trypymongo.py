from pymongo import MongoClient
import pprint
import re

#client = MongoClient(host="localhost",port=27017)
client = MongoClient("mongodb://localhost:27017/")

db = client["chinook"]

customers_collection = db["customers"]
#print(customers_collection)

#doc1 = customers_collection.find_one()
#print(doc1)

for all_doc in customers_collection.find():
    print(all_doc)

for rec in customers_collection.find({}, {"_id":0, "LastName": 1, "FirstName":1}):
    print(rec)

rgx = re.compile('^G.*?$', re.IGNORECASE)

cursor = customers_collection.find({"LastName":rgx})
num_docs = 0
for document in cursor:
    num_docs += 1
    pprint.pprint(document)
    print()

print("# of documents found: " + str(num_docs))