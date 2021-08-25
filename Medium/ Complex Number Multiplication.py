

# Question Link :: "https://leetcode.com/problems/complex-number-multiplication/"


# Solution #

class Solution:
    def complexNumberMultiply(self, num1: str, num2: str) -> str:
        lst1 = num1.split("+")
        lst2 = num2.split("+")
        real1, real2 = int(lst1[0]), int(lst2[0])
        
        imag1 , imag2 = int(lst1[1][:-1]), int(lst2[1][:-1])
        
        ans_real = (real1 * real2) - (imag1 * imag2)
        
        ans_imag = (real1 * imag2) + (imag1 * real2)
        
        return str(ans_real) + "+" + str(ans_imag) + "i"