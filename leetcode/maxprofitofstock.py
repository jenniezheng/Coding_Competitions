import math
import sys
sys.setrecursionlimit(100000)
class Solution(object):
    def maxProfit(self, prices, fee):
        self.memo={}
        if(len(prices)<=1):
            return 0
        newprices=[prices[0]]

        for x in range(1,len(prices)-1):
            before=prices[x-1]
            current=prices[x]
            thenext=prices[x+1]
            if(before < current and current > thenext):
                newprices.append(current)
            elif (before > current and current < thenext):
                newprices.append(current)
        if(prices[len(prices)-1]>newprices[len(newprices)-1]):
            newprices.append(prices[len(prices)-1])
        prices=newprices
        if(prices[0]>prices[1]):
            prices=prices[1:]

        return self.maxProfitHelper(math.inf,prices,fee,0)

    def maxProfitHelper(self, last_smallest, prices, fee, index):

        if((last_smallest,index) in self.memo):
            return self.memo[(last_smallest,index)]
        if(index>=len(prices)-1):
            return 0
        last_smallest=min(last_smallest,prices[index])
        poss=prices[index+1]-last_smallest-fee
        if(poss>0):
            print("HI")
            sol=max( poss+
                self.maxProfitHelper(math.inf, prices, fee, index+2),
                self.maxProfitHelper(last_smallest, prices, fee, index+2))
        else:
            sol= self.maxProfitHelper(last_smallest, prices, fee, index+2)
        self.memo[(last_smallest,index)]=sol
        return sol


s=Solution()
print(s.maxProfit( prices =[2,1,4,4,2,3,2,5,1,2], fee = 1))