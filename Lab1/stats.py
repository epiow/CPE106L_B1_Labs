def mean(n):
    result = 0
    for i in n:
        result += i
    return result / len(n)

def median(n):
    a = sorted(n)
    index = len(n)
    if(index % 2 == 0):
        return (a[int(index/2) - 1] + a[int(index/2)])/2
    return a[int(index/2)]

# 1, 2, 3, 4, 5, 6
def mode(n):
    hash = dict()

    if len(n) == 0:
        return "No Mode"

    for num in n:
        if num not in hash:
            hash[num] = 1    
        else:
            hash[num] += 1

    mostFreq = []
    max = 0
    for key, values in hash.items():
        if values > max:
            max = values

    for key, values in hash.items():
        if values == max:
            mostFreq.append(key)
    return mostFreq

def main():
    array = input("Enter an array of numbers: ")
    array = array.split(" ")
    array = [int(x) for x in array]

    print("Mean:", mean(array))
    print("Median:", median(array))
    print("Mode:", mode(array))

if __name__ == "__main__":
    main()
