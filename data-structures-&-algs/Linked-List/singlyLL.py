# Implementation for a single node
class ListNode(object):

    def __init__(self, val):
        self.data = val # Value within current node
        self.next = None # Pointed to the next node

# Implementation for Singly Linked List
class LinkedList:

    def __init__(self):
        self.head = ListNode(-1) # Starting the head off with dummy data so we can remove from the start.
        self.tail = self.head 

    def insertEnd(self, data):
        self.tail.next = ListNode(data)
        self.tail = self.tail.next
    
    def remove(self, index):
        i = 0
        curr = self.head # Not accounting for dummy node as we assume there are actual nodes within our list
        # Traverse list to stop just before the node to be deleted
        while i < index and curr:
            curr = curr.next
            i+=1
        if curr:
            curr.next = curr.next.next # Adjust pointer of our current node to point to the deleted items neighbor

    def print(self):
        curr = self.head.next # Starts from the actual data as self.head points to dummy data
        while curr:
            print(f"{curr.data} -> ", end="")
            curr = curr.next
        print()

# Create Linked List object
my_list1 = LinkedList()
my_list1.insertEnd(2) # This is the actual first node
my_list1.insertEnd(3)
my_list1.print()
my_list1.remove(1)
my_list1.print()
