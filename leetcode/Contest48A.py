class Solution:
    def __init__(self):
        self.current_min = -1
        self.current_second_min=-1;


    def findSecondMinimumValue(self, root):
    	if(root==None):
    		return self.current_second_min;
    	elif(  root.val < self.current_min or self.current_min == -1):
    		self.current_second_min=self.current_min;
    		self.current_min=root.val;
    	elif( ( root.val < self.current_second_min or self.current_second_min == -1) and self.current_min != root.val ):
    		self.current_second_min=root.val;
    	self.findSecondMinimumValue(root.left);
    	self.findSecondMinimumValue(root.right);
    	return self.current_second_min;