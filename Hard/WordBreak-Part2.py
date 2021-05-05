

#  Question Link :: "https://practice.geeksforgeeks.org/problems/word-break-part-23249/1"


# Solution //


class Solution:
    def wordBreak(self, n, dictionary, s):
        # code here
        self.dictionary = dictionary
        self.sentences=[]
        self.s=s
        self.rec("",0,len(s))
        
        return self.sentences
    
    
    def rec(self,string,index,l):
        
        if index == l:
            self.sentences.append(string)
        else:
            temp_str = ""
            while index<l:
                
                temp_str+=self.s[index]
                
                if temp_str in self.dictionary:
                    if string == "":
                        self.rec(temp_str,index+1,l)
                    else:
                        self.rec(string+" "+temp_str,index+1,l)
                        
                
                index+=1
        

