def feb(n):
    if n == 1 | n == 2:
        return 1
    a = 1
    b = 1
    for i in range(3, n + 1):
        c = a + b
        a = b
        b = c
    return b

n = int(input())
for i in range(1, n + 1):
    print(feb(i) % (2 ** 31), end=", ")