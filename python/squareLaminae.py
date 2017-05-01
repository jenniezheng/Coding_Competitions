import math
#Problem 173 from projecteuler.net
tilesAvailable=int(input())
myMax=int(math.sqrt(tilesAvailable))
sum=0
for k in range (2,myMax, 2):
	add=(tilesAvailable//k-k)//2
	if(add>0):
		sum+=add
print(sum)