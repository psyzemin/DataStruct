from SQueue import SQueue
class BinTree:
    def __init__(self,data,left = None,right = None):
        self._data = data
        self._left = left
        self._right = right

    def isempty(self):
        return self._data == None
    def insert_left(self,data):
        if self._left is None:
            self._left = BinTree(data)
        else:
            p = BinTree(data,self._left)
            self._left = p
    def insert_right(self,data):
        if self._right is None:
            self._right = BinTree(data)
        else:
            p = BinTree(data,None,self._left)
            self._right = p
    def DLR(self):
        print(self._data)
        if self._left:
            self._left.DLR()
        if self._right:
            self._right.DLR()
    def BFS(self):
        s = SQueue()
        s.enqueue(self)
        while not s.isempty():
            p = s.dequeue()
            print(p._data)
            if p._left is not None:
                s.enqueue(p._left)
            elif p._right is not None:
                s.enqueue(p._right)


if __name__ == "__main__":
    b = BinTree(0)
    for i in range(5):
        b.insert_left(i)
        for n in range(2):
            b.insert_right(n)
    b.BFS()
