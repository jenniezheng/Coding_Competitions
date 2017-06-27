filename="B-large.in"
def main():
	f = open(filename, "r")
	o = open("output.out", "w")
	testCases=int(f.readline())
	for x in range(1, testCases+1):
		print("")
		size=int(f.readline())
		wordArr=[]
		for num in range(0, size):
			line=f.readline()
			line=line.split('\n')[0]
			print(line)
			wordArr.append(line)
		sol=solver(wordArr)
		print(sol)
		o.write("Case #"+str(x)+": "+sol+"\n")
	f.close()
	o.close();


def solver(wordArr):
	metSingle=False;
	for word in wordArr:
		count=word.count('X');
		if(count==1):
			if(metSingle):
				return "IMPOSSIBLE"

			else:
				metSingle=True;

		elif(count!=2):
			return "IMPOSSIBLE"
	if(metSingle==False):
		return "IMPOSSIBLE"
	metSingle=False;
	for x in range(0,len(wordArr)):
		
		count=0;
		for y in range(0,len(wordArr)):
			if(wordArr[y][x]=='X'):
				count+=1;
		if(count==1):
			if(metSingle):
				return "IMPOSSIBLE"

			else:
				metSingle=True;

		elif(count!=2):
			return "IMPOSSIBLE"
	if(metSingle==False):
		return "IMPOSSIBLE"
	
	for x in range(0,len(wordArr)):
		haveBuddy=False;
		count=wordArr[x].count('X');
		if(count==1):
			continue;
		for y in range(0,len(wordArr)):
			if(x!=y  and wordArr[x]==wordArr[y]):
				haveBuddy=True;
				break;
		if(haveBuddy==False):
			return "IMPOSSIBLE" 
	
	return "POSSIBLE"
	
main();