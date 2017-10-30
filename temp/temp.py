import sys
import re

class Solution:

    def diffWaysToCompute(self, myinput):
        mydict={}
        processed=[]
        myinput=re.split('(\D)', myinput)
        print(myinput)

        for x in range(0,len(myinput),2):
            myinput[x]=int(myinput[x])

        res=self.diffWaysToComputeHelper(myinput,0,len(myinput)-1,mydict)
        return res

    def compute(self,op1,ch,op2):
        sol=-1
        if(ch=='*'):
            sol=op1*op2
        elif(ch=='+'):
            sol=op1+op2
        elif(ch=='-'):
            sol=op1-op2
        return sol

    def diffWaysToComputeHelper(self, myinput,s,e,mydict):
        tup=(s,e)
        if(tup in mydict):
            return mydict[tup]
        solutions=[]
        if(e==s):
            solutions.append(myinput[e])
        else:
            for cut in range(s+1,e,2):
                op=myinput[cut]
                leftSet=self.diffWaysToComputeHelper(myinput,s,cut-1,mydict)
                rightSet=self.diffWaysToComputeHelper(myinput,cut+1,e,mydict)
                for n in leftSet:
                    for m in rightSet:
                        solutions.append(self.compute(n,op,m))
        mydict[tup]=solutions
        return solutions
s=Solution()
print(s.diffWaysToCompute("11+1+2-5-4*2"));