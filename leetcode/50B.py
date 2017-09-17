class MapSum:
    def __init__(self):
        self.map = {}


    def insert(self, key, val):
        self.map[key]=val
        print(self.map)


    def sum(self, prefix):
        total=0
        for key in self.map:
            if(key.startswith(prefix)):
                total+=self.map[key]
        return total;



# Your MapSum object will be instantiated and called as such:
obj = MapSum()
obj.insert('aa',2)
obj.insert('abb',2)
obj.insert('Ca',2)
param_2 = obj.sum('C')
print(param_2)