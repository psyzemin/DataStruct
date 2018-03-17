from LList import LNode

class LStack():
    def __init__(self):
        self._top = None
    def isempty(self):
        return self._top == None
    def push(self,elem):
        p = self._top
        node = LNode(elem,p)
        self._top = node
    def pop(self):
        p = self._top
        self._top = p.next
        return p.elem
    def top(self):
        return self._top.elem


if __name__ == '__main__':
    st1 = LStack()
    st1.push(2)
    st1.push(5)
    print(st1.top())
    while True:
        if st1.isempty():
            break
        else:
            print(st1.pop())