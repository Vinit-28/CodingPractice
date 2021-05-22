


#   Question Link :: "https://practice.geeksforgeeks.org/problems/find-duplicate-rows-in-a-binary-matrix/1"



# Solution #


class trie:
    def __init__(self,data):
        self.data = data
        self.child_0 = None
        self.child_1 = None


class Solution:
    def repeatedRows(self, arr, m ,n):
    
        root = trie(0)
        dup = []
        for i in range(m):
            if self.insert(arr[i],root):
                dup.append(i)
        
        return dup
    
    
    
    
    def insert(self,lst,root):
        
        is_exists = True
        temp = root
        for i in lst:
            
            if i==0:
                
                if temp.child_0 == None:
                    temp.child_0 = trie(i)
                    is_exists = False
                
                temp = temp.child_0
            
            elif i==1:
                
                if temp.child_1 == None:
                    temp.child_1 = trie(i)
                    is_exists = False
                
                temp = temp.child_1
        
        return is_exists
            
