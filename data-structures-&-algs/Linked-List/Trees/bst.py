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

def minValueNode(root):
    curr = root
    # curr.left will be null eventually, meaning the parent, curr, is the last left most node and therefore the smallest node
    while curr and curr.left:
        curr = curr.left
    return curr

def remove(root, val):
    # Check if tree is empty
    if not root:
        return None
    
    
    if val > root.val:
        root.right = remove(root.right, val)
    elif val < root.val:
        root.left = remove(root.left, val)
    else:
        # Case 1: node has 0 or 1 child noe
        if not root.left:
            return root.right
        elif not root.right:
            return root.left
        # Case 2: node has 2 child nodes
        else:
            # Find and return the smallest value withing the rightmost tree to be the new parent
            minNode = minValueNode(root.right)
            root.val = minNode.val
            root.right = remove(root.right, minNode.val)
    return root

# Create tree node object
root = TreeNode(2)
leaf1 = TreeNode(1)
leaf2 = TreeNode(3)
# Connecting nodes to form tree
root.left = leaf1
root.right = leaf2
# Printing tree in sorted manner
print(root.left.val, root.val, root.right.val)

# Adding a new node
insert(root, 4)
print(root.left.val, root.val, root.right.val, root.right.right.val)

# Deleting that same new node
remove(root, 4)
print(root.left.val, root.val, root.right.val)