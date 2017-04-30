
def removeComma(s):
	return s.replace(',', '');

def main():
	dirs=[]
	ch=[]

	for x in range (1,11):
		with open('text/ch'+str(x),'r') as f:
			arr=[]
			for line in f:
			    for word in line.split():
			    		arr.append(word)
			ch.append(arr);

	with open('text/lines','r') as f:
		for line in f:
			dirone=[]
			for word in line.split():
		    		dirone.append(int(removeComma(word))-1);
			dirs.append(dirone);
	for dirOne in dirs:
		chapter=ch[dirOne[0]]
		word=chapter[dirOne[1]]
		try:
			lett=word[dirOne[2]]
			print(lett,end="");
		except:
			#out of bounds
			print("!",end="");
	print("")

if __name__ == "__main__":
    main()