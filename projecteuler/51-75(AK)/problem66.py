import numpy
import math
from operator import mod

def GetXHJ(S):
    m,d = 0,1
    a = a0 = int(math.sqrt(S))
    result = [a0]
    while a != a0*2:
        m = a*d-m
        d = (S-m*m)/d
        a = int((m+math.sqrt(S))/d)
        result += [a]
    return result

def GetJianjin(LFS):
    idx = 1
    result = [LFS[0]]
    while True:
        a,b = 1,result[idx-1]
        for i in range(idx-2,-1,-1):
            a,b=b,a+b*result[i]
        yield [a,b]
        idx += 1
        result += [LFS[mod(idx-2,len(LFS)-1)+1]]
 
def GetMinx(D):
    for k in GetJianjin(GetXHJ(D)):
        if k[1]*k[1]-D*k[0]*k[0] == 1:
            return k[1]
     
#main
maxp = -1
maxD = 1
for D in range(5,1001):
    if math.sqrt(D)==int(math.sqrt(D)):
        continue
    t = GetMinx(D)
    if t > maxp:
        maxp = t
        maxD = D
print(maxD)
