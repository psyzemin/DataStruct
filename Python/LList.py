
class LNode:
    def __init__(self,elem,next_ = None):
        self.elem = elem
        self.next = next_

class LList:
    def __init__(self):
        self._head = None
        self._rear = None
        self._num = 0

    def clear(self):
        self._head = None
        self._rear = None
        self._num = 0

    def isempty(self):
        return self._head is None

    def len(self):
        if self.isempty():
            return 0
        else:
            p = self._head
            n = 0
            while p is not self._rear:
                p = p.next
                n += 1
            return n

    def __len__(self):
        return self._num

    def prepend(self,elem):
        if self.isempty():
            p = LNode(elem,self._head)
            self._head = p
            self._rear = self._head
            self._num += 1
        else:
            p = LNode(elem,self._head)
            self._head = p
            self._num +=1

    def append(self,elem):
        p = LNode(elem)
        if self.isempty():
            self._head = p
            self._rear = self._head
            self._num += 1
        else:
            self._rear.next = p
            self._rear = p
            self._num += 1

    def insert(self,elem,i):
        ins = LNode(elem)
        if self.isempty():
            raise ValueError("List is empty")
        p = self._head
        for n in range(1,i-1):
            if p.next is None:
                raise ValueError("List len is too short")
            p = p.next
        ins.next = p.next.next
        p.next = ins
        self._num += 1

    def pop_last(self):
        p = self._head
        if self.isempty():
            raise ValueError("LList is empty")
        if self._head.next is None:
            e = p.elem
            self._head = None
            return e
        while p.next.next is not None:
            p = p.next
        e = p.next.elem
        p.next = None
        self._rear = p
        self._num -= 1
        return e

    def pop(self):
        if self.isempty():
            raise ValueError("LList is empty")
        e = self._head.elem
        self._head = self._head.next
        self._num -= 1
        return e

    def delete(self,i):
        if self.isempty():
            raise ValueError("List is empty")
        else:
            p = self._head
            for n in range(1,i-1):
                if p is self._rear:
                    raise ValueError("List len is too short")
                p = p.next
            p.next = p.next.next
            self._num -= 1

    def find(self,pred):
        if self.isempty():
            raise ValueError("LList is empty")
        else:
            p = self._head
            while p is not None:
                if pred(p.elem):
                    return p.elem
                p = p.next

    def filter(self,pred):
        if self.isempty():
            raise ValueError("LList is empty")
        else:
            p = self._head
            while p is not None:
                if pred(p.elem):
                    yield p.elem
                p = p.next

    def foreach(self,proc):
        p = self._head
        while p is not None:
            proc(p.elem)
            p = p.next

    def sort(self):
        if self.isempty():
            return
        crt = self._head.next
        while crt is not None:
            x = crt.elem
            p = self._head
            while p is not crt:
                if p.elem <= x:
                    p = p.next
                else:
                    y = p.elem
                    p.elem = x
                    x = y
                    p = p.next
            crt.elem = x
            crt = crt.next

    def printall(self):
        if self.isempty():
            return
        else:
            p = self._head
            while p is not self._rear:
                print(p.elem,end="," if p.next is not self._rear else "\n")
                p = p.next








