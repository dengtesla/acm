import numpy 
def cal(n):
	ans=int(n**0.5)
	for x in range(100):
		n*=100
		tmp=ans*10
		while tmp*tmp<=n:
			if tmp*tmp==n:
				return 0
			tmp+=1
		ans=tmp-1
	return sum([int(x) for x in str(ans)[0:100:]])
print sum([cal(x) for x in range(100)])
