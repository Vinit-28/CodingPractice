

# Question Link :: "https://leetcode.com/problems/design-hashset/"


# Solution #

class MyHashSet:

    def __init__(self):
        self.bucketSize = 1000
        self.bucket = [[]]*self.bucketSize 

        
    def add(self, key: int) -> None:
        index = key%self.bucketSize
        if not self.contains(key):
            self.bucket[index].append(key)

            
    def remove(self, key: int) -> None:
        index = key%self.bucketSize
        if self.contains(key):
            self.bucket[index].remove(key)
        

    def contains(self, key: int) -> bool:
        index = key%self.bucketSize
        for i in self.bucket[index]:
            if key == i:
                return True
        return False
            