a, b, l, r=list(map(int, input().split(" ")))
import math
def minUnique (a,b,l,r):
	if (r<=a):
		return r-l+1;
	if (b>=a):
		startset=(l-1)%(a+b)+1
		endset=(r-1)%(a+b)+1
		if(r-l>=a+b):
			if(startset==1 and endset==a and r-l==a+b):
				return a;
			else: 
				return 1+a;
		else:
			if(startset>=4):
				if(endset>=4):
					return 1;
				else:
					return endset+1;
			if(endset>=4):
				return 4-startset;
			return endset-startset+1;
	if(a>b):
		startset=(l-1)%(a+b)+1
		endset=(r-1)%(a+b)+1
		if(r-l>=a+b):
			if(startset==1 and endset==a):
				return 2*a-b;
			else: 
				return 2*a-b+1;
		else:
			if(endset>4):
				endset=0;
			if(startset>4):
				startset=0;
			else:
				startset=4-startset
			return math.min(startset+endset, a)






print(minUnique(a,b,l,r))