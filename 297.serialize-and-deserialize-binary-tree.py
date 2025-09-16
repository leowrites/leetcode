#
# @lc app=leetcode id=297 lang=python3
#
# [297] Serialize and Deserialize Binary Tree
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import deque
class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        # i // 2 ^ height
        # bfs?
        # after we visit a node, we can append itself 2 times
        # in case there are children. when traversing, this lets us 
        # know if there is a left and a right child
        # queue:
        values = []
        queue = deque([root])
        while queue:
            node = queue.popleft()
            if node is None:
                values.append("None")
                continue
            values.append(str(node.val))
            queue.append(node.left)
            queue.append(node.right)
        return ",".join(values)
        

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        root = TreeNode()
        queue = deque([root])
        data = deque(data.split(","))
        if data[0] == "None":
            return []
        while data:
            val = data.popleft()
            node = queue.popleft()
            if val != "None":
                node.val = int(val)
                node.left = TreeNode(None)
                node.right = TreeNode(None)
                queue.append(node.left)
                queue.append(node.right)
        queue = deque([root])
        while queue:
            node = queue.popleft()
            if node is None:
                continue
            if node.left and node.left.val is None:
                node.left = None
            if node.right and node.right.val is None:
                node.right = None
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
        return root
            
        

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))
# @lc code=end

