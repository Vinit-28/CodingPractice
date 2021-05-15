


#  Question Link :: "https://practice.geeksforgeeks.org/problems/d857113143f69fab217cf5dab978535542f3cbb1/1"



#  Solution ## 



class Solution:
    
    def wordBreak(self, A, B):
        # code here
        self.dictionary = B
        self.s=A
        self.signal = False
        self.rec("",0,len(A))
        
        return self.signal
    
    
    def rec(self,string,index,l):
        
        
        if index == l:
            self.signal = True
            return
        else:
            temp_str = ""
            while index<l:
                
                if self.signal:
                    return
                temp_str+=self.s[index]
                
                if temp_str in self.dictionary:
                    if string == "":
                        self.rec(temp_str,index+1,l)
                    else:
                        self.rec(string+" "+temp_str,index+1,l)
                        
                
                index+=1
    
