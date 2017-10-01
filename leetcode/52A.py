class Solution:
    def repeatedStringMatch(self, A, B):
        chars=set()
        for c in A:
            chars.add(c)

        for c in B:
            if (c not in chars):
                return -1
        multiplier=1
        while(B not in A*multiplier):
            multiplier+=1
            if(len(A)*multiplier > len(B) *4):
                return -1
        return multiplier

sol=Solution()
print(sol.repeatedStringMatch("a",
"a"*1000))