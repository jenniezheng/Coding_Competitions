myset=set({'a','b','c'})

for size in range(1,9):
    print("Total of "+str(len(myset))+' of length '+str(2**size))
    newSet=set()
    for el1 in myset:
        if(len(newSet)>=50):
            break
        for el2 in myset:
            if(len(newSet)>=50):
                break
            word=el1+el2
            dup=False
            for start2 in range(len(word)):
                for start1 in range(start2+1,len(word)):
                    length=0
                    if(dup):
                        break
                    if(start1+length>=len(word)):
                        break
                    #print(start1,start2,length)
                    while(word[start2+length]==word[start1+length]):
                        #print(start1,start2,length)
                        length+=1

                        if(start2+length>=start1):
                            #print("Yes")
                            dup=True
                            break
                        if(start1+length>=len(word)):
                            break
            if(not dup):
                word=el1+el2
                newSet.add(el1+el2)
    myset=newSet
    #for s in myset:
     #   print(s)


for s in myset:
    print(s)
    break