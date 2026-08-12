def lowbit(x):
    return x & -x

def work(n):
    for i in range(2 ** n, 0, -1):
        x = i
        k = bin(x).count('1')
        if (lowbit(x)) == (2 ** k):
            return x

for i in range(1, 21):
    print("\"", work(2 * i), "\"", sep="", end=", ")