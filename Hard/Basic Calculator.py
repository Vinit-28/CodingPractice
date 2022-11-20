

# Question Link :: "https://leetcode.com/problems/basic-calculator/description/"


# Solution #

class Solution:
   
    def calculate(self, s: str) -> int:
        return self.solve_paranthesis(s.replace(" ", ""), 0)[0]

    def solve_paranthesis(self, s, index):
        result = 0
        num = 0
        operation = '+'
        length = len(s)
        while index < length:
            ch = s[index]
            if ch >= '0' and ch <= '9':
                num = num*10+int(ch)
                index += 1
            elif ch == '+' or ch == '-':
                result += num if operation == '+' else -num
                num = 0
                operation = ch
                index += 1
            else:
                result += num if operation == '+' else -num
                num = 0
                if ch == '(':
                    res = self.solve_paranthesis(s, index+1)
                    if operation == '-':
                        result += -res[0] if res[0] > 0 else abs(res[0])
                    else:
                        result += res[0]
                    index = res[1]+1
                else:
                    return result, index
        
        result += num if operation == '+' else -num
        return result, length

                    
                
        
        