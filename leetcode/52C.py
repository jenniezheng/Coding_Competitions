class Solution:
    def knightProbability(self, N, K, r, c):
        self.prob={}
        self.N=N
        #K ,r,c -> prob
        return self.knightProbabilityHelper(K,r,c)
    def knightProbabilityHelper(self, K,r, c):
        #off
        if(r<0 or c<0 or r>=self.N or c>=self.N):
            return 0
        #done
        if(K==0):
            return 1
        else:
            if (K,r,c) in self.prob:
                return self.prob[(K,r,c)]
            sol= (.125*self.knightProbabilityHelper( K-1, r-2, c-1)
                + .125*self.knightProbabilityHelper( K-1, r+2, c+1)
                + .125*self.knightProbabilityHelper( K-1, r-2, c+1)
                + .125*self.knightProbabilityHelper( K-1, r+2, c-1)
                + .125*self.knightProbabilityHelper( K-1, r-1, c-2)
                + .125*self.knightProbabilityHelper( K-1, r+1, c+2)
                + .125*self.knightProbabilityHelper(K-1, r-1, c+2)
                + .125*self.knightProbabilityHelper( K-1, r+1, c-2))
            self.prob[(K,r,c)]=sol
            return sol

sol=Solution()
print(sol.knightProbability(3,2,0,0))