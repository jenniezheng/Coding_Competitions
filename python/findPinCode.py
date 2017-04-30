from queue import *
def reverse(a):
	r=0;
	while a > 0:
		r *= 10;
		r += a % 10;
		a //= 10;
	return r;

def gatherPin():
	obtained=set();
	q = Queue(maxsize=0);
	sols=set();
	q.put([100,0])

	while not q.empty():
		num=q.get();
		if(num[0] not in obtained):
			obtained.add(num[0]);
			if(num[1]==16):
				sols.add(num[0]+5);
				sols.add(num[0]*3);
				sols.add(reverse(num[0]))
			else:
				q.put([5+num[0],num[1]+1]);
				q.put([3*num[0],num[1]+1]);
				q.put([reverse(num[0]),num[1]+1]);
			
	
	for num in sols:
		if(1000<=num and num<=9999 and num not in obtained):
			print(num)

gatherPin();