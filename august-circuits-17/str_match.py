import numpy as np
import sys

string=list(map(int,list(input().split()[0])))
length=int(input().split()[0])
needed=list(map(int,input().split(" ")))

needed_arr=np.zeros(10)
for num in needed:
	needed_arr[num]+=1;

#start with all zeroes
actual_arr=np.empty([10,len(string)+1],int)
actual_arr[:,0]=np.zeros(10);

current_arr=np.zeros(10);
for x in range(0, len(string)):
	num=string[x];
	current_arr[num]+=1;
	actual_arr[:,x+1]=current_arr;




count=0
for start in range (0,len(string)-length+1):
	if(start%50==0):
		#check still possible:
		total=actual_arr[:,len(string)]
		diff=np.subtract(total, actual_arr[:,start])
		diff2=np.subtract(diff, needed_arr);
		all_non_neg=(diff2 >= 0).all();
		if(not all_non_neg):
			break;

	low=start+length
	high=len(string)+1
	med=(low+high)//2;
	while(low+1<high):
		diff=np.subtract(actual_arr[:,med], actual_arr[:,start])
		diff2=np.subtract(diff, needed_arr);
		all_non_neg=(diff2 >= 0).all();
		if(all_non_neg):
			high=med;
		else:
			low=med;
		med=(low+high)//2;
	
	diff=np.subtract(actual_arr[:,med], actual_arr[:,start])
	diff2=np.subtract(diff, needed_arr);
	all_non_neg=(diff2 >= 0).all();
	#assume med doesn't work
	min_work=med+1
	if(all_non_neg):
		#then med itself works
		min_work=med

	#length string is maximum possible
	max_work=len(string);
	count+=(max_work-min_work+1);
print(count)