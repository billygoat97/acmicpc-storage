import math

a,b = input().split()
a = int(a)
b = int(b)

print(math.factorial(a)//(math.factorial(b)*math.factorial((a-b))))
