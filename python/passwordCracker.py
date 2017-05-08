
def main():
	testCases=int(input())
	while (testCases):
		numPasses=int(input())
		arrPasses=input().split()
		concatedPasses=input()
		res=crackPass(set(), arrPasses, [], concatedPasses);
		print(res);
		testCases-=1;


def crackPass(memo, wordsAvail, wordsChosen, concatedStr):
	memo.add(concatedStr);
	if(concatedStr==""):
		return " ".join(wordsChosen)
	csl=len(concatedStr)
	for word in wordsAvail:
		print(word, concatedStr)
		wl=len(word)
		if(csl>= wl and concatedStr[ : wl]== word and concatedStr[wl:] not in memo):
			tryThis=crackPass(memo, wordsAvail, wordsChosen+[word], concatedStr[wl:]);
			if(tryThis!="WRONG PASSWORD"):
				return tryThis;
	return "WRONG PASSWORD";
main();