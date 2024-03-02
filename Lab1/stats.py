def mean(n):
    result = 0
    for i in n:
        result += i
    return result / len(n)

def median(n):
    a = sorted(n)
    index = len(n)
    if(index % 2 == 0):
        return (a[index/2] + a[index/2 + 1])/2
    return a[int(index/2)]

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
    print("Hello World!")
    print("Mean:", mean([1,2,3,4]))
    print("Median:", median([1,2,3]))
    print("Mode:", mode([1]))

if __name__ == "__main__":
    main()
