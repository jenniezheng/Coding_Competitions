import math

def main():
	targetNum = int(input())
	exponentNum = int(input())
	print(expressWays(0, 1, exponentNum,targetNum));



def expressWays(currentSum, base, exp, target):
	if(currentSum==target):
		return 1;
	newSum=math.pow(base, exp)+currentSum;
	if(newSum>target):
		return 0;
	return expressWays(currentSum, base+1, exp, target) + \
		expressWays(newSum, base+1, exp, target);

main();