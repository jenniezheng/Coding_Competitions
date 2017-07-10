geneNum=int(input());
genes=input().split();
healths=input().split();
dicty={}
for x in range (0, len(genes)):
	dicty[genes[x]]=int(healths[x]);
