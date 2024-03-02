import random
#random stuff
def get_random_pie():
    flavors = ['apple', 'cherry', 'blueberry', 'pumpkin', 'cream']
    random_flavor = random.choice(flavors)
    return random_flavor

random_pie = get_random_pie()

print(f"I love {random_pie} pie")