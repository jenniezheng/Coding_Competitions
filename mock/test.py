class Solution(object):
    def hIndex(self, citations):
        if(len(citations)==0):
            return 0
        citations.sort()
        freqs_arr=[]
        preNum=citations[0]
        count = 1
        for x in range(1,len(citations)):
            cit=citations[x]
            if(cit==preNum):
                count+=1
            else:
                freqs_arr.append((preNum,count))
                count=1
                preNum=cit
        freqs_arr.append((preNum,count))

        before_or_at=0
        at_or_after=len(citations)
        for x in range(0,len(freqs_arr)):
            num,freq=freqs_arr[x]
            before_or_at+=freq
            if(x!=0):
                at_or_after-=freq
        print(before_or_at,at_or_after)


s=Solution()
print(s.hIndex([3, 0, 6, 1, 5]))