import math
limit=1000001
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

num_tests=int(input())
for t in range(num_tests):
    x=int(input())
    if(isPrime[x]):
        print("YES")
    else:
        print("NO")