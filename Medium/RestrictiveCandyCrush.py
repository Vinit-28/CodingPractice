


#  Question Link :: "https://practice.geeksforgeeks.org/problems/8c8f95810b05b4cab665f2997d36991bd58308a2/1"



# Solution #


class Solution:
    
    def Reduced_String(self, k, s):
        stack = ""
        char_match = 0
        for i in range(len(s)):
            
            if stack!="" and stack[-1] == s[i]:
                char_match+=1
                stack += s[i]
            
            else:
                
                char_match = 1
                stack += s[i]
            
            
           
            if char_match == k:
                
                l = len(stack)
                if (l - k) <= 0:
                    stack = ""
                else:
                    stack = stack[0:(l-k)]
                
                    char_match = self.count(stack,len(stack)-1,stack[-1])
        
        
        return stack
    
    
    def count(self,s,lst_index,ch):
        c = 0
        
        while lst_index>=0:
            if s[lst_index] == ch:
                c+=1
            
            else:
                return c
            
            lst_index-=1
        
        return c
        

