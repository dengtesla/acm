a = 2
b = 3
counter = 0
for i in range(1,1001):
    a,b = b+a,2*a+b
    if len(str(b)) > len(str(a)):
        counter += 1
print (counter)
