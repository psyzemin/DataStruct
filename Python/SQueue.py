'''队列'''
class SQueue():
    def __init__(self,init_len = 8):
        self._elems = init_len*[0]
        self._head = 0
        self._num = 0
        self._len = init_len
    def isempty(self):
        return self._num == 0
    def peek(self):
        if self.isempty():
            raise ValueError("SQueue is empty")
        return self._elems[self._head]
    def dequeue(self):
        if self.isempty():
            raise ValueError("SQueue is empty")
        e = self._elems[self._head]
        self._head = (self._head+1) % self._len
        self._num -=1
        return e
    def enqueue(self,elem):
        if self._len == self._num:
            self.__extend()
        self._elems[(self._head+self._num) % self._len] = elem
        self._num += 1
    def __extend(self):
        old_len = self._len
        self._len *= 2
        new_elems = [0] * self._len
        for i in range(old_len):
            new_elems[i] = self._elems[(self._head + i) % old_len]
        self._head = 0
        self._elems = new_elems

if __name__ == "__main__":
    q1 = SQueue()
    for i in range(1,11):
        q1.enqueue(i)
    while True:
        if q1.isempty():
            break
        print(q1.dequeue())

