

# Question Link :: "https://practice.geeksforgeeks.org/problems/validate-an-ip-address-1587115621/1"


## Solution ##

def isValid(s):
    #code here
    lst = s.split('.')
    lst_len = 0
    
    for i in lst:
        try:
            n = int(i)
            if n<0 or n >= 256 or (len(i) > 1 and i[0] == '0'):
                return 0
        except:
            return 0
        
        lst_len+=1
    
    if lst_len==4:
        return 1
    return 0

