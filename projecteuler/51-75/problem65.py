import numpy as np
import sys  
  
def gcd(a,b):  
    if a%b == 0:  
        return b  
    else :  
        return gcd(b,a%b)  



e = []
v = 1
for i in range(150):
    if i==0:
        e.append(2)
    elif i%3==0 or i%3==1:
        e.append(1)
    elif i%3==2:
        e.append(v*2)
        v+=1
a = [0]*100
b = [0]*100
b[99] = 1
a[99] = e[99]

for i in range(99):
    b[98-i] = a[99-i]
    a[98-i] = e[98-i]*a[99-i] + b[99-i]

##print(a[0])
##print(b[0])
##print(gcd(a[0],b[0]))
ans = 0
while a[0]!=0:
    ans += (a[0]%10)
    ##print(a[0]%10)
    a[0] //=10
print(ans)
