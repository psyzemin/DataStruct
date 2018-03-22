'''基于堆的优先队列'''
class TreeQue:
    def __init__(self,mylist = []):
        self._list = list(mylist)
        if mylist:
            self.buildheap()
    def isempty(self):
        return self._list == None
    def peek(self):
        if self.isempty():
            raise ValueError("Que is empty")
        return self._list[0]
    def enqueue(self,elem):
        self._list.append(None)
        self.shiftup(elem,len(self._list)-1)
    def shiftup(self,elem,last):
        list,i,j = self._list,last,(last-1)//2
        while i > 0 and elem < list[j]:
            list[i] = list[j]
            i,j = j,(j-1)//2
        list[i] = elem
    def dequeue(self):
        if self.isempty():
            raise ValueError("Que is empty")
        e0 = self._list[0]
        e = self._list.pop()
        if not self.isempty():
            self.shiftdown(e,0,len(self._list))
        return e0
    def shiftdown(self,elem,begin,end):
        list,i,j = self._list,begin,begin*2+1
        while j < end:
            if j+1 < end and list[j+1] < list[j]:
                j += 1
            if elem < list[j]:
                break
            list[i] = list[j]
            i,j = j,j*2+1
        list[i] = elem
    def buildheap(self):
        end = len(self._list)
        for i in range(end//2,-1,-1):
            self.shiftdown(self._list[i],i,end)
    def printall(self):
        for i in range(len(self._list)):
            print(self._list[i],end=" ")

if __name__ == "__main__":
    l1 = []
    for i in range(20,1,-1):
        l1.append(i)
    print(l1)
    t1 = TreeQue(l1)
    t1.printall()
    l1.sort()
    print("\n")
    print(l1)