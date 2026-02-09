# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def _inorder_traversal(self,node: Optional[TreeNode], result: List[int])-> None:
        if not node:
            return 
        self._inorder_traversal(node.left,result)
        result.append(node.val)
        self._inorder_traversal(node.right,result)
    
    def _construct(self,values: List[int], left:int, right:int) -> Optional[TreeNode]:
        if(left>right):
            return None
        mid = left + (right-left)//2

        root = TreeNode(values[mid])
        root.left = self._construct(values,left,mid-1)
        root.right = self._construct(values,mid+1,right)

        return root

    def balanceBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        sorted_values: List[int] = []

        self._inorder_traversal(root,sorted_values)

        return self._construct(sorted_values,0,len(sorted_values)-1)
