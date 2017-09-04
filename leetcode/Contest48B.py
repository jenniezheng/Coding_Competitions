class Solution:
	def What(self, root, L, R):
		while(root and R < root.val):
			root=root.left;
		while (root and root.val < L):
			root=root.right;
		if(not root):
			return None
		root.left=self.What(root.left,L,R);
		root.right=self.What(root.right,L,R);
		return root;
	def trimBST(self, root, L, R):
		root=self.What(root, L, R);
		root=self.What(root, L, R);
		return root;