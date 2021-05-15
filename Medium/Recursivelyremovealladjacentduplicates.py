

#    Question Link :: "https://practice.geeksforgeeks.org/problems/recursively-remove-all-adjacent-duplicates0744/1"




#  Solution   #


class Solution:
    def remove (self, S):
        self.string = S
        self.remove_recursively(len(S))
        return self.string


    def remove_recursively(self,length):
        index = new_len = 0
        new_string = ""
        while index < length:
            if index<length-1 and self.string[index] == self.string[index+1]:
                pass
            elif index>0 and self.string[index] == self.string[index-1]:
                pass
            else:
                new_string+=self.string[index]
                new_len+=1
            
            index+=1
        
        if self.string == new_string:
            return
        else:
            self.string=new_string
            self.remove_recursively(new_len)


