class Solution(object):
    def numSubarrayProductLessThanK(self, nums, k):
        if(len(nums)==0):
            return 0
        total=0
        firsttime=True
        product=1
        last_end=-1
        for start in range(len(nums)):
            if(start!=0):
                product=product/int(nums[start-1])
            for end in range(last_end+1,len(nums)):
                last_end=end
                start_num=nums[end]
                newproduct=start_num*product
                if(newproduct>=k):
                    last_end=end-1
                    break
                else:
                    product=newproduct

            if(product<k):
                total+=last_end-start+1
                """
                print('[',end='')
                for x in range(start,last_end+1):
                    print(nums[x],end=',')
                print(']')
                """
        return total
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
s=Solution()
print(s.numSubarrayProductLessThanK([10, 5, 1,1,2, 6],100))