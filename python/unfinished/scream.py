line1=input().split(" ");
a=int(line1[0])
b=int(line1[1])
line2=input().split(" ");
c=int(line2[0])
d=int(line2[1])
found=False
tries=0;
k1=0
k2=0
while tries<1000000:
	print( b+a*k, d+c*k)
	input()
	if b+a*k1 > d+c*k2:
		k2+=1
	elif b+a*k1 < d+c*k2:
		k1+=1	
	else:
		print(k+1)
		found=True
		break
if not found:
	print(-1)
