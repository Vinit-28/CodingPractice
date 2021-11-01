

#  Question Link :: "https://practice.geeksforgeeks.org/problems/circular-prime-number0230/1?utm_source=gfgpractice&utm_medium=banner&utm_campaign=Practice_Explore_POD_Top_Banner"


#  Solution #

class Solution:
	def isCircularPrime(self, n):
		# Code here
	    strNum = str(n);
	    for i in range(len(strNum)):
	        if not self.isPrime(int( strNum[i:] + strNum[0:i] )):
	            return 0;
	    
	    return 1;
	
	
	def isPrime(self, n):
	    if n == 1: 
	        return False
	    for i in range(2, n//2+1):
	        if n%i == 0:
	            return False;
	    return True;
