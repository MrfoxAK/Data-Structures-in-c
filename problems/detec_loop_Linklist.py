# User function Template for python3
'''
        # Node Class
        class Node:
            def __init__(self, data):   # data -> value stored in node
                self.data = data
                self.next = None
    
'''


class Solution:
    # Function to check if the linked list has a loop.
    def detectLoop(self, head):
        # code here

        slow = head
        fast = head

        while fast and fast.next:
            # slow jumps one step further

            # fast jumps two steps forward

            slow = slow.next
            fast = fast.next.next
            # At some point fast meets slow if loop is found in linked list
            if fast == slow:
                return True
        return False
