class Solution:
    def checkValidString(self, s):
        self.s=list(s)
        return self.isValid(0,0)

    def isValid(self, index, num_open):
        for x in range (index,len(self.s)):
            if(self.s[x]=='('):
                num_open+=1
            elif(self.s[x]==')'):
                if(num_open==0):
                    return False
                else:
                    num_open-=1
            elif(self.s[x]=='*'):
                try1=self.isValid(x+1,num_open)
                if(try1):
                    return True
                self.s[x]='('
                if(self.isValid(x,num_open)):
                    return True
                self.s[x]=')'
                if(self.isValid(x,num_open)):
                    return True
                return False
        return num_open==0

s=Solution();
print(s.checkValidString("()"))