# Definition for a binary tree node.
class TreeNode:
     def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

import math
from collections import defaultdict

class Solution:
    def longestUnivaluePath(self, root):
        if root is None:
            return 0
        self.startNode=0

        self.longestFromNode=defaultdict(lambda: 0)
        self.longestPath(root,math.inf,0)
        print(self.longestFromNode)
        length=1
        for key in self.longestFromNode:
            if(self.longestFromNode[key]>length):
                length=self.longestFromNode[key]
        return length - 1

    def longestPath(self, root, value,parent):
        if root is None:
            return 0
        if(root.val==value):
            pos1=self.longestPath(root.left, value,parent)
            pos2=self.longestPath(root.right, value,parent)
            mymax= 1+max(pos1,pos2)
            self.longestFromNode[parent]=mymax
            return mymax
        else:
            self.startNode+=1
            start=self.startNode
            pos1=self.longestPath(root.left, root.val, start)
            pos2=self.longestPath(root.right, root.val, start)
            mymax= 1+pos1+pos2
            self.longestFromNode[start]=mymax
            return 0




a=TreeNode(5)
b=TreeNode(5)
d=TreeNode(5)
e=TreeNode(5)
f=TreeNode(5)
a.left=b
a.right=d
b.left=e
b.right=f
e.right=TreeNode(5)
e.left=TreeNode(1)
f.right=TreeNode(1)
f.left=TreeNode(1)
d.right=TreeNode(1)
d.left=TreeNode(1)
sol=Solution()
print(sol.longestUnivaluePath(a))