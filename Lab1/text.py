print("Enter file name: ")

inp = input()

if(inp == "0"): 
    exit()

infile = open(inp, "r")

lines = []

for i in infile:
    lines.append(i[:-1])

print("Enter line number to print: ")

inp = int(input())

if(inp == 0): 
    exit()

print(lines[inp - 1])