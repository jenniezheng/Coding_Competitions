class Solution(object):
    def minDistance(self, start, target):
        self.memo={}
        self.start=start
        self.target=target
        sol=self.minDistanceHelper(0,0)
        #print(self.memo)
        return sol
    def minDistanceHelper(self, startindex, targetindex):
        if((startindex,targetindex) in self.memo):
            return self.memo[(startindex,targetindex)]
        if(targetindex)==len(self.target):
            #delete til target
            return len(self.start)-startindex
        elif(startindex==len(self.start)):
            #insert til target
            return len(self.target)-targetindex
        elif(self.start[startindex]==self.target[targetindex]):
            return self.minDistanceHelper(startindex+1,targetindex+1)
        else:
            sol= 1+min(
                self.minDistanceHelper(startindex+1,targetindex),
                self.minDistanceHelper(startindex,targetindex+1),
                self.minDistanceHelper(startindex+1,targetindex+1),
            )
            self.memo[(startindex,targetindex)]=sol
            return sol
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """

s=Solution()
print(s.minDistance("dinitrophenylhydrazine","acetylphenylhydrazine"))

