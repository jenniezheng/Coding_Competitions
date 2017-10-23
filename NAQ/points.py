num=int(input())
points=set()

for n in range(num):
    x,y=map(int,input().split())
    points.add((x,y))

count=0
for data in points:
    x,y=data
    if(x,y+2018) in points:
        count+=1
    if(x-2018,y) in points:
        count+=1
    if(x+1118,y+1680) in points:
        count+=1
    if(x-1118,y+1680) in points:
        count+=1
    if(x+1680,y+1118) in points:
        count+=1
    if(x-1680,y+1118) in points:
        count+=1
print(count)
