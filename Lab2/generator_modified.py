"""
Program: generator.py
Author: Abads
Generates and displays sentences using a simple grammar
and vocabulary.  Words are chosen at random.
"""

import random

with open("articles.txt", "r") as article:
    articles = article.read().split("\n")

with open("nouns.txt", "r") as noun:
    nouns = noun.read().split("\n")

with open("articles.txt", "r") as preposition:
    prepositions = preposition.read().split("\n")

with open("articles.txt", "r") as verb:
    verbs = verb.read().split("\n")

def sentence():
    """Builds and returns a sentence."""
    return nounPhrase() + " " + verbPhrase()

def nounPhrase():
    """Builds and returns a noun phrase."""
    return random.choice(articles) + " " + random.choice(nouns)

def verbPhrase():
    """Builds and returns a verb phrase."""
    return random.choice(verbs) + " " + nounPhrase() + " " + \
           prepositionalPhrase()

def prepositionalPhrase():
    """Builds and returns a prepositional phrase."""
    return random.choice(prepositions) + " " + nounPhrase()

def main():
    """Allows the user to input the number of sentences
    to generate."""
    number = int(input("Enter the number of sentences: "))
    for count in range(number):
        print(sentence())\
    

# The entry point for program execution
if __name__ == "__main__":
    main()
