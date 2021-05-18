


#  Question Link :: "https://practice.geeksforgeeks.org/problems/rank-the-permutations2229/1"




# Solution #


class Solution:
    
	def findRank(self, S):
		#Code here
		self.mod = 1000003
		string=""
		l=0
		for i in sorted(S):
		    if l > 0 and string[-1] == i:
		        return 0
		    string+=i
		    l+=1
		
		per_perm = self.get_per_permu(l)
		rank = 0
		
		while True:
		    index = string.find(S[0])
		    rank = (rank%self.mod) + ((per_perm%self.mod * index%self.mod)%self.mod)
		    string = string[0:index] + string[index+1:]
		    S = S[1:]
		    l-=1
		    if l==0:
		        break
		    per_perm = (per_perm//l)
		    
        return (((rank%self.mod)+1)%self.mod)
		
	
	def get_per_permu(self,str_len):
	    fact = 1
	    for i in range(1,str_len+1):
	       fact *= i
	   
	    
	    return (fact//str_len)
		

