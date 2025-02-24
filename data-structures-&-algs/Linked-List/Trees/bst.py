# Binary Search Tree
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.right = None
        self.left = None

def search(root, target):
    # Check if tree is empty
    if not root:
        return False 
    
    if target > root.val:
        return search(root.right, target)
    elif target < root.val:
        return search(root.left, target)
    else:
        return True
    
def insert(root, val):
    # if tree is empty, node to be inserted becomes our root node
    if not root:
        root = TreeNode(val)
    
    # Find where to insert the new node
    if val > root.val:
        root.right = insert(root.right, val)
    elif val < root.val:
        root.left = insert(root.left, val)
    return root


# Create tree node object
root = TreeNode(2)
leaf1 = TreeNode(1)
leaf2 = TreeNode(3)
root.left = leaf1
root.right = leaf2
print(root.val, root.left.val, root.right.val)
print(search(root, 4))

insert(root, 4)
print(search(root,4))
print(root.val, root.left.val, root.right.val, root.right.right.val)