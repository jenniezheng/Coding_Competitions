import math
[N,K]=map(int, input().split(" "));
Xarr=list(map(int, input().split(" ")));
Yarr=list(map(int, input().split(" ")));
smallest_required_radius_arr=[0]*N;
for i in range (0, N):
	dist=math.sqrt(Xarr[i]**2+Yarr[i]**2)
	min_radius=math.ceil(dist);
	smallest_required_radius_arr[i]=min_radius

smallest_required_radius_arr.sort()
print(smallest_required_radius_arr[K-1]);