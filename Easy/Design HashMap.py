

# Question Link :: "https://leetcode.com/problems/design-hashmap/"


# Solution #

class MyHashMap:

    def __init__(self):
        self.size = 1000001
        self.lst = [None for _ in range(self.size)]

    def put(self, key: int, value: int) -> None:
        self.lst[key] = value

    def get(self, key: int) -> int:
        return self.lst[key] if self.lst[key]!=None else -1

    def remove(self, key: int) -> None:
        self.lst[key] = None

