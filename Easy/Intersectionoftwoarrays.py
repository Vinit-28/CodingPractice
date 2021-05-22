


#  Question Link :: "https://practice.geeksforgeeks.org/problems/intersection-of-two-arrays2404/1"





# Solution #



class Solution:
    def NumberofElementsInIntersection(self,a, b, n, m):
        #return: expected length of the intersection array.
        
        #code here
        comm = dict()
        count = 0
        for i in a:
            comm[i] = 1
        
        for i in b:
            try:
                comm[i] += 1
                count+=1
                if comm[i] > 2:
                    count-=1
            except:
                pass
        
        
        return count    

