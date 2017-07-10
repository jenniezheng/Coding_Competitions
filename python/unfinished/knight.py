import queue
import math

def inbounds(pos,size):
	maxi=math.max(pos[0],pos[1])
	mini=math.min(pos[0],pos[1])
	return 0<=mini and maxi<size;
def countMoves(vert,hori,size):
	q = queue.Queue()
	q.put((0,[0,0]))
	while not q.empty():
	    pos,moves=q.get();
	    =tup.get(0);

	    print(pos);

