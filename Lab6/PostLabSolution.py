'''
Code written by Sangilan, FP O.
'''
from pymongo import MongoClient

client = MongoClient()

db_name = "chinook"

db = client["chinook"]

# defining collection names 
collections = ["artists", "albums", "tracks"]

#here we see JSON implementation of the schema
schemas = {
    "artists": {
        "artistId": {"type": "objectId"},  
        "name": {"type": "string"}
    },
    "albums": {
        "albumId": {"type": "objectId"},  
        "title": {"type": "string"},
        "artistId": {"type": "objectId", "foreignField": "artists.artistId"}  
    },
    "tracks": {
        "trackId": {"type": "objectId"},  #
        "name": {"type": "string"},
        "albumId": {"type": "objectId", "foreignField": "albums.albumId"},  
        "mediaTypeId": {"type": "int"},
        "genreId": {"type": "int"},
        "composer": {"type": "string"},
        "milliseconds": {"type": "int"},
        "bytes": {"type": "int"},
        "unitPrice": {"type": "decimal"}  
    }
}

# Create collections with schemas
for collection_name, schema in schemas.items():
    # check if collection already exists
    if collection_name not in db.list_collection_names():
        db.create_collection(collection_name, validator=schema)
        print(f"Collection '{collection_name}' created with schema successfully!")
    else:
        print(f"Collection '{collection_name}' already exists.")

# closing connections
client.close()

