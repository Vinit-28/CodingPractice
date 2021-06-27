

# Question Link :: "https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1"



# Solution #

class Solution:
    def longestCommonSubstr(self, S1, S2, n, m):
        MaxLenght = index1 = index2 = 0 
        for index1 in range(n):
            if S1[index1] in S2:
                for index2 in range(m):
                    if S2[index2] == S1[index1]:
                        
                        CI1,CI2 = index1,index2
                        CSL = 0
                        while CI1<n and CI2<m and S1[CI1] == S2[CI2]:
                            CSL+=1
                            CI1+=1
                            CI2+=1
                        if CSL>MaxLenght:
                            MaxLenght=CSL
        return MaxLenght