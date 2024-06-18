def factorial(num) :
    sum = 1
    for i in range(num, 0, -1) :
        sum *= i
    return sum

n = int(input())

result = factorial(n)

print(result)