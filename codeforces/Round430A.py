import math
[all_radius,crust_radius]=map(int, input().split("\n")[0].split(" "))
num_sausage=int(input())
count=0
for n in range (0,num_sausage):
	x,y, sausage_radius=map(int, input().split("\n")[0].split(" "))
	if(x**2+y**2 >= (all_radius-crust_radius+sausage_radius)**2 and x**2+y**2 <= (all_radius-sausage_radius)**2):
		count+=1;
print(count)