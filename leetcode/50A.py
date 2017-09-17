class Solution:
    def validPalindrome(self, s):
        return self.isPalindrome(list(s),False);
    def isPalindrome(self, s, deleted_one):
        for x in range (0, len(s)//2):
            if(s[x]!=s[len(s)-x-1]):
                if(not deleted_one):
                    try1=s[:x] + s[x+1 :]
                    try2=s[:len(s)-x-1] + s[len(s)-x :]
                    return self.isPalindrome(try1,True) or self.isPalindrome(try2,True)
                else:
                    return False
        return True

s=Solution();
print(s.validPalindrome("CAABAC"))