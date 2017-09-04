class Solution:

	def pathSum(self, nums):
		"""
		:type nums: List[int]
		:rtype: int
		"""
		overall_total=0
		mydict={}
		for num in nums:
			depth=num//100
			pos=(num%100)//10-1
			val=num%10
			node_num=(1<<(depth-1))+pos
			mydict[node_num]=val
		for key in mydict:
			if (key*2 in mydict or key*2+1 in mydict):
				continue #not leaf
			total=mydict[key]
			parent=key//2
			while(parent in mydict):
				total+=mydict[parent]
				parent=parent//2
			overall_total+=total
		return overall_total