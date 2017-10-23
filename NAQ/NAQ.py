import math

n,m, r=map(int,input().split())
if(m==0 and n==1):
    print('yes')
    exit(0)

candle_locs=[]

for index in range(n):
    x,y=map(int,input().split())
    candle_locs.append((x,y))

cutting_lines=[]

for index in range(m):
    a,b,c=map(int,input().split())
    cutting_lines.append((a,b,c))

for lineA in range(m):
    for lineB in range(lineA+1,m):
        a,b,c=cutting_lines[lineA]
        a2,b2,c2=cutting_lines[lineB]
        intersect=False
        int_x=((c2-c*b2)/b)/(a*b2/b-a2)
        int_y=(ax+c)/-b
        if(int_x**2+int_y**2>r):
            #don't intersect


my_arr=[0] * int(math.pow(2,m))

for candle_loc in candle_locs:
    x,y=candle_loc
    side_total=0
    for line_index in range(m):
        a,b,c=cutting_lines[line_index]
        if (a*x+b*y+c > 0):
            side_total+=int(math.pow(2,line_index))
    my_arr[side_total]+=1
    if(my_arr[side_total]>1):
        print('no')
        exit(0)

for num in my_arr:
    if(num!=1):

        print('no')
        exit(0)

print('yes')