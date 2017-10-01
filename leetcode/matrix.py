class Solution(object):
    def updateMatrix(self, matrix):
        self.matrix=matrix;
        self.rows=len(self.matrix)
        self.cols=len(self.matrix[0])
        self.total=self.rows*self.cols;
        self.result=[[-1 for i in range(self.cols)] for j in range(self.rows)]
        self.done=0
        self.count_zeros();
        self.zeros=len(self.zeros_locs)
        #if lots of zeroes
        if (self.zeros/self.total>.2):
            self.nonzero_find_closest_distance()
        else:
            self.zero_find_closest_distance()
        return self.result;
    def count_zeros(self):
        zeros_locs=[];
        for i in range (0,self.rows):
            for j in range (0,self.cols):
                if self.matrix[i][j]==0:
                    zeros_locs.append([i,j])
        self.zeros_locs=zeros_locs;
    def nonzero_find_closest_distance(self):
        for i in range (0,self.rows):
            for j in range (0,self.cols):
                if self.matrix[i][j]==0:
                    self.result[i][j]=0
                else:
                    sol=False
                    dist=0
                    while(not sol):
                        for delim in range (0,dist+1):
                            if(sol):
                                break
                            for x,y in [(delim,dist-delim),(-delim,dist-delim),(-delim,-dist+delim),(delim,-dist+delim) ]:
                                other_i,other_j=(x+i,y+j)
                                if self.in_bounds(other_i,other_j) and self.matrix[other_i][other_j]==0:
                                    self.result[i][j]=dist
                                    sol=True
                                    break;
                        dist+=1

    def zero_find_closest_distance(self):
        for dist in range (0,self.rows+self.cols):
            for loc in self.zeros_locs:
                for delim in range (0,dist+1):
                    for x,y in [(delim,dist-delim),(-delim,dist-delim),(-delim,-dist+delim),(delim,-dist+delim) ]:
                        i,j=(x+loc[0],y+loc[1])
                        if self.in_bounds(i,j) and self.result[i][j]==-1:
                            self.result[i][j]=dist
                            self.done+=1
                            if(self.done==self.total):
                                return

    def in_bounds(self, i, j):
        return (0<=i and i<self.rows
            and 0<=j and j<self.cols)


s=Solution();
print(s.updateMatrix([[0,1,0],[2,1,2],[2,0,2]]))