import random

class DLNode:
    def __init__(self,elem,next_ = None,prev = None):
        self.next = next_
        self.prev = prev
        self.elem = elem

class DLList:
    def __init__(self):
        self._head = None
        self._rear = None
    def isempty(self):
        return self._head is None

    def prepend(self,elem):
        p = DLNode(elem,self._head,None)
        if self.isempty():
            self._rear = p
        else:
            p.next.prev = p
        self._head = p

    def append(self,elem):
        p = DLNode(elem,None,self._rear)
        if self.isempty():
            self._head = p
        else:
            p.prev.next = p
        self._rear = p

    def pop(self):
        if self.isempty():
            raise ValueError("List is empty")
        e = self._rear
        self._rear = e.prev
        if self._rear is None:
            self._head = None
        else:
            e.prev.next = None

    def printall(self):
        if self.isempty():
            raise ValueError("List is empty")
        p = self._head
        while p is not None:
            print(p.elem,end=", "if p.next is not None else "\n" )
            p = p.next

    def reverse(self):
        pre = self._head
        aft = self._rear
        if self.isempty() or pre is aft:
            return

        while pre is not aft:
            if pre.next is aft:
                break
            p = pre.elem
            pre.elem = aft.elem
            aft.elem = p
            pre = pre.next
            aft = aft.prev

    def sort(self):
        if self.isempty():
            return
        crt = self._head.next
        while crt is not None:
            p = self._head
            while p is not crt:
                if p.elem >= crt.elem:
                    m = p.elem
                    p.elem = crt.elem
                    crt.elem = m
                    p = p.next
                else:
                    p = p.next
            crt = crt.next


