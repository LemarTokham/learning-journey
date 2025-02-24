# Binary Search Tree
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.right = None
        self.left = None

def search(root, target):
    if not root:
        return False # No rootnode, tree is empty
    
    if target > root.val:
        return search(root.right, target)
    elif target < root.val:
        return search(root.left, target)
    else:
        return True
    


# Create tree node object
root = TreeNode(2)
leaf1 = TreeNode(1)
leaf2 = TreeNode(3)
root.left = leaf1
root.right = leaf2
print(root.val, root.left.val, root.right.val)
print(search(root, 4))