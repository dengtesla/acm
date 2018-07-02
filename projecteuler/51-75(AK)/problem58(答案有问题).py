def PrimeQ(n):
    if n <= 1:
        return False
    for i in range(2,int(n**0.5+1)):
        if n%i == 0:
            return False;
    return True;
 
k = 1
dif = 2
prime_counter = 0
while True:
    k += dif * 4
    dif += 2
    prime_counter += PrimeQ(k+dif)
    prime_counter += PrimeQ(k+2*dif)
    prime_counter += PrimeQ(k+3*dif)
    if prime_counter*10<(2*dif+1):
        print (dif+1)
        break
