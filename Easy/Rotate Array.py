

#  Question Link :: "https://practice.geeksforgeeks.org/problems/rotate-array-by-n-elements-1587115621/1"



# Solution #

class Solution:
    #Function to rotate an array by d elements in counter-clockwise direction. 
    def rotateArr(self,arr,d,n):
        #Your code here
        lst = arr[d:] + arr[0:d]
        
        for i in range(n):
            arr[i] = lst[i]
  
