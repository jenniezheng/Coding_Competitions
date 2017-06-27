import math

filename="C-small-attempt2.in"
def main():
	f = open(filename, "r")
	o = open("output.out", "w")
	testCases=int(f.readline())
	for x in range(1, testCases+1):
		print("")
		nums=f.readline().split(" ")

		numFriends=int(nums[0])
		numQuestions=int(nums[1])
		
		if(numFriends==1):
			otherSol=f.readline().split('\n')[0];
			yourSol=f.readline().split('\n')[0];
			print(otherSol)
			print(yourSol)
			otherNumRight=int(f.readline())
			print("Correct: ",otherNumRight)
			sol=solverOne(yourSol,otherSol,otherNumRight)
		
		
		print("SOL: ",sol)
		o.write("Case #"+str(x)+": "+str(sol)+"\n")
	f.close()
	o.close();

def differences(yourSol, otherSol):
	count=0;
	for x in range(0,len(yourSol)):
		if(yourSol[x]!=otherSol[x]):
			count+=1;
	print("Diffs: ",count)
	return count;

def solverOne(yourSol, otherSol, numRight):
	numDiff=differences(yourSol,otherSol)
	if(numRight+numDiff<=len(yourSol)):
		return numDiff+numRight;
	else:
		return 2*len(yourSol)-(numDiff+numRight)


	
main();