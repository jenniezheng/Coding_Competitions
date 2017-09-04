import math
class Solution:
	def widthOfBinaryTree(self, root):
		level = [[root,0]]
		nextLevel = []
		max_width=0

		while len(level)!=0:
			leftmost=level[0][1];
			rightmost=level[0][1];
			for node in level:
				if node[0].left != None:
					nextLevel.append([node[0].left, 2*node[1]])
				if node[0].right != None:
					nextLevel.append([node[0].right, 2*node[1]+1])
				if(node[1]<leftmost):
					leftmost=node[1]
				if(node[1]>rightmost):
					rightmost=node[1]
			width=rightmost-leftmost+1;
			if(max_width<width):
				max_width=width
			level = nextLevel
			nextLevel = [];

		return max_width
