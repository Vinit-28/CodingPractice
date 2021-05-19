


#  Question Link :: "https://practice.geeksforgeeks.org/problems/largest-divisibility-test3444/1"




# Solution #

class Solution:
    def largestDivisible (self, n):
        # code here 
        s = ""
        length=0
        l = sorted(n)
        for i in range(len(l)-1,-1,-1):
            s+=l[i]
            length+=1
        
        self.signal = False
        self.max = ""
        self.rec("",length,s)
        
        if self.signal:
            return self.max
        
        return "Not Possible"
    
    
    def rec(self,number,length,string):
        
        
        if length == 0:
            if int(number)%17 == 0 :
                self.max=number
                self.signal = True
        
            return
        
        
        for index in range(0,length):
            
            if self.signal:
                return
            
            self.rec(number+string[index],length-1, string[0:index]+string[index+1:])

