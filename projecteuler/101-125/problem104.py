def pend(a,cnt):
    a = list(str(a))
    b = a[0:9]
    cc = a[-1:-10:-1]
    b.sort()
    cc.sort()
    #print(cc)
    flag = 1
    for i in range(0,8):
        if b[i]!=str(i+1):
            flag = 0
            break

    for i in range(0,8):
        #print(c[i])
        if cc[i]!=str(i+1):
            flag = 0
            break
    if flag==1:
        return 1
    return 0

a=1
b=1
i = 2;



cnt=2
while 1:
    c = a + b
    d = c
    cnt+=1
    if cnt % 10000 == 0:
        print(cnt)
    if d>100000000000 and pend(d,cnt)==1:
        print(cnt)
        break
    a = b
    b = c
    ##if cnt==2749:
    ##    print(c)
    ##    break
