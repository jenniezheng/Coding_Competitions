class Solution:
    def checkPossibility(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        modified=False;
        for x in range (0,len(nums)-1):
        	if( nums[x] <= nums[x+1]):
        		continue
        	else:
        		if(modified):
        			return False
        		else:
        			modified=True
        			if(x==0 or nums[x-1] <=nums[x+1]):
        				nums[x]=nums[x+1]
        			else:
        				nums[x+1]=nums[x]
        			#print(nums)
        return True