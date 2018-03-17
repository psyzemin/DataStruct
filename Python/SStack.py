class SStack():
    def __init__(self):
        self._elems = []
    def isempty(self):
        return self._elems == []
    def top(self):
        if self.isempty():
            raise ValueError("Stack is empty")
        return self._elems[-1]
    def pop(self):
        if self.isempty():
            raise ValueError("Stack is empty")
        return self._elems.pop()
    def push(self,elem):
        self._elems.append(elem)

if __name__ == '__main__':
    st1 = SStack()
    st1.push(2)
    st1.push(5)
    while True:
        if st1.isempty():
            break
        else:
            print(st1.pop())