from math import gcd

v1=[]
v2=[]

n = int(input())


imsi = input().split()
for i in range(n):
    v1.append(int(imsi[i]))


m = int(input())
imsi = input().split()
for i in range(m):
    v2.append(int(imsi[i]))

answer = 1
for i in range(n):
    for j in range(m):
        t = gcd(int(v1[i]),int(v2[j]))
        answer *= t
        v1[i] /= t
        v2[j] /= t

ans = []
if answer > 999999999:
    answer %= 1000000000
    for i in range(9):
        imsi = int(answer%10)
        ans.insert(0,str(imsi))
        answer /= 10
    
    for i in range(9):
        print(ans[i],end='')
    print()
else:
    print(int(answer))