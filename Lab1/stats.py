def mean(n):
    result = 0
    for i in n:
        result += i
    return result / len(n)

def median(n):
    a = sorted(n)
    if(len(n) % 2 == 0):
        return (a[len(n)/2] + a[len(n)/2 + 1])/2
    return a[len(n)/2]

def main():
    print("Hello World!")

if __name__ == "__main__":
    main()
