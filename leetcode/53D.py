class Solution:
    def minStickers(self, stickers, target):
        target_needed={}
        for char in target:
            if(char in target_needed):
                target_needed[ord(char)-ord('a')]+=1
            else:
                target_needed[ord(char)-ord('a')]=1

        myset=set()
        for stick in stickers:
            sticks_given=[0]*26
            for char in stick:
                sticks_given[ord(char)-ord('a')]+=1
            myset.add(tuple(sticks_given))
        print(myset)

    def min_count(self,stickets,target):
        print(target_needed)

s=Solution()
print(s.minStickers(["with", "example", "science"], "thehat"))