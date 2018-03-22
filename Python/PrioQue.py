'''基于list的优先队列'''
class PrioQue:
    def __init__(self,mylist = []):
        self._list = list(mylist)
        self._list.sort(reverse=True)
    def isempty(self):
        return self._list == None
    def enqueue(self,elem):
        i = len(self._list)-1
        while i >= 0:
            if self._list[i] <= elem :
                i -= 1
            else:
                break
        self._list.insert(i+1,elem)
    def dequeue(self):
        if self.isempty():
            raise ValueError("Que is empty")
        return self._list.pop()
    def peek(self):
        if self.isempty():
            raise ValueError("Que is empty")
        return self._list[-1]
    def printall(self):
        for i in self._list:
            print(i , end = " ")




