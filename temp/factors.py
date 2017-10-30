import math
a=2
b=int(input())/2
limit=b+1

isPrime=[True]*limit
top=math.sqrt(limit)
isPrime[0]=False
isPrime[1]=False

current=0
while(current<top):
    current+=1
    while(current+1<len(isPrime) and isPrime[current]==False):
        current+=1

    for nonprime in range(current*2,limit,current):
        isPrime[nonprime]=False

prime_factors=set()
for x in range(a,b+1):
    if(isPrime[x]):
        prime_factors.add(x)

print(prime_factors)
