# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Codec:

    def serialize(self, root):
        if root is None:
            return ''
        res=str(root.val)
        left=self.serialize(root.left)
        if(left!=''):
            res+='LD'+left +'LU'

        right=self.serialize(root.right)
        if(right!=''):
            res+='RD'+right+'RU'
        return res

    def deserialize(self, data):
        if(data==''):
            return None
        #self.right=deserialize from first RD to last RU, data in between
        #self.left=deserialize from first LD to last LU, data in between
        #
        return
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
a=TreeNode(1)
a.left=TreeNode(2)
c=Codec()
print(c.serialize(a))