class Solution:
	def average(self,M, row_num, col_num):
		rows=len(M);
		cols=len(M[0]);

		num_valid_points=0;
		total=0;
		for i in range (row_num-1, row_num+2):
			for j in range (col_num-1, col_num+2):
				if(0<=i and i<rows and 0<=j and j<cols):
					num_valid_points+=1;
					total+=M[i][j];

		return math.floor(total/num_valid_points);
	def imageSmoother(self, M):
		rows=len(M);
		cols=len(M[0]);

		Res= [[0 for x in range(cols)] for y in range(rows)];

		for i in range (0,rows):
			for j in range (0,cols):
				Res[i][j]=self.average(M,i,j);
		return Res;