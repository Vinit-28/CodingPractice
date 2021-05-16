

# Question Link :: "https://practice.geeksforgeeks.org/problems/relative-sorting4323/1"



# Solution #

class Solution:
    # A1[] : the input array-1
    # N : size of the array A1[]
    # A2[] : the input array-2
    # M : size of the array A2[]
    
    #Function to sort an array according to the other array.
    def relativeSort (self,A1, N, A2, M):
        # Your Code Here
        temp = []
        res = []
        A1.sort()
        ocur = self.CountOccurence(A1)
        
        for i in A2:
            
            try:
                oc = ocur[i]
                for j in range(oc):
                    A1.remove(i)
                    res.append(i)
            
            except:
                pass
        
        
        return res+A1
    
    
    def CountOccurence(self,lst):
        ocur = dict()
        
        for i in lst:
            
            try:
                ocur[i] +=1
            except:
                ocur[i] = 1
        return ocur

