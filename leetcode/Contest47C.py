class Solution:
    def constructArray(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[int]
        """
        total=n
        num_in_order=n-k
        num_diff=k
        arr=[]
        for x in range (0,num_diff):
            if(x%2==0):
                arr.append(total-x//2)
            else:
                arr.append(x//2+1)
        start=arr[num_diff-1]
        for x in range (0,num_in_order):
            if(num_diff%2==0):
                arr.append(start+x+1)
            else:
                arr.append(start-x-1)
        return arr