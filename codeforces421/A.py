totalPages, readMin, readMax, incr, reread=list(map(int, input().split(" ")))

def numDays (c, v0, v1, a, l):
	if c==0:
		return 0;
	if c<=v0:
		return 1;
	days=1;
	c-=v0;
	
	readamount=v0
	while c>0:
		c+=l;
		days+=1;
		readamount+=a;
		if(readamount>v1):
			readamount=v1;
		c-=readamount;
	return days;

print(numDays(totalPages, readMin, readMax, incr, reread))