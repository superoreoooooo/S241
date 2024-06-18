import sys

read = sys.stdin.readline
data = list(map(int, read().split(',')))

def sort(l) :
    n = len(l)
    for i in range(0, n, 1) :
        for j in range(0, n - i - 1, 1) :
            if (l[j] > l[j + 1]) :
                tmp = l[j]
                l[j] = l[j + 1]
                l[j + 1] = tmp
    return l

result = sort(data)

print(result)