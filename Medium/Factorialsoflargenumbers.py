

#   Question Link :: "https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1"




#  Solution  //


class Solution:
    def factorial(self, N):
        #code here
        fac=1
        for i in range(1,N+1):
            fac*=i
        
        lst = [int(i) for i in str(fac)]
        return lst

