def subLinkedList(l1, l2):

    def make(head):
        c = 0
        cur = head
        while(cur):
            c = c*10+cur.data
            cur = cur.next
        return c
    a = make(l1)
    b = make(l2)
    c1 = abs(a-b)
    if(c1 == 0):
        return Node(0)
    else:
        c1 = str(c1)
        dum = Node(0)
        ans = dum
        for i in c1:
            ans.next = Node(int(i))
            ans = ans.next
        return dum.next
