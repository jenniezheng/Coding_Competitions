from collections import OrderedDict
class RangeModule:
    def __init__(self):
        self.ranges=OrderedDict()
    def addRange(self, left, right):
        leftmost=left
        rightmost=right-1
        todelete=[]
        for ileft in self.ranges:
            iright=self.ranges[ileft]
            #not necessary
            if (ileft<=leftmost and iright>=rightmost):
                return
            elif (ileft>=leftmost and iright<=rightmost):
                todelete.append(ileft)
            elif (rightmost>=ileft-1 and leftmost<ileft):
                todelete.append(ileft)
                rightmost=iright
            elif (leftmost<=iright+1 and leftmost>ileft):
                todelete.append(ileft)
                leftmost=ileft
        for left in todelete:
            del self.ranges[left]
        self.ranges[leftmost]=rightmost
        print(self.ranges)

    def queryRange(self, left, right):
        right=right-1
        for ileft,iright in self.ranges.items():
            #not encompassed
            if (ileft<=left and iright>=right):
                return True
        return False

    def removeRange(self, left, right):
        right=right-1
        todelete=[]
        toadd=[]
        for ileft in self.ranges:
            iright=self.ranges[ileft]
            if (ileft<=left and iright>=right):
                todelete.append(ileft)
                toadd.append((ileft,left-1))
                toadd.append((right+1,iright))
                break
            #encompassed
            elif (ileft>=left and iright<=right):
                todelete.append(ileft)
            #right side
            elif (right>=ileft and left<ileft):
                todelete.append(ileft)
                toadd.append((right+1,iright))
            elif (left<iright and left>ileft):
                todelete.append(ileft)
                toadd.append((ileft,left-1))
        for left in todelete:
            del self.ranges[left]
        for add in toadd:
            myleft,myright=add
            self.ranges[myleft]=myright
        print(self.ranges)

# Your RangeModule object will be instantiated and called as such:
obj = RangeModule()
obj.addRange(11,20)
obj.addRange(25,30)
obj.addRange(20,25)