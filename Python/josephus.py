from LCList import LCList

def josephus_1(n,k,m):
    people = list(range(1,n+1))

    i = k-1
    for num in range(n):
        count = 0
        while count < m:
            if people[i]>0:
                count +=1
            if count is m:
                print(people[i],end="")
                people[i] = 0
            i = (i+1)%n
        if num < n-1:
            print(", ",end="")
        else:
            print("")
    return

def josephus_2(n,k,m):
    people = list(range(1,n+1))
    num,i= n,k-1
    for num in range(n,0,-1):
        i = (i+m-1)%num
        print(people.pop(i),end=(", "if num>1 else "/n"))
    return

class josephus(LCList):
    def run(self,m):
        for i in range(m):
            self._head = self._head.next

    def __init__(self,n,k,m):
        LCList.__init__(self)
        for i in range(1,n+1):
            self.append(i)
        self.run(k-1)
        while self._head is not None:
            self.run(m-1)
            print(self.pop(),end=(", " if self._head is not None else ""))




