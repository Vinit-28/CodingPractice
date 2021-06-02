

#   Question Link :: "https://practice.geeksforgeeks.org/problems/trailing-zeroes-in-factorial5134/1"


# Solution #


class Solution:
    def trailingZeroes(self, n):
    	#code here 
    	c=0
    	
    	while True:
    	    c += (n//5)
    	    
    	    n = n//5
    	    
    	    if n < 5:
    	        break
    	
    	return c
