


//   Question Link :: "https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1"



// Solution //



class Solution
{
    public:
  
    bool is_pair_valid(char open, char end){
    
        if(open == '(' && end == ')')
            return true;
        else if( open == '[' && end == ']' )
            return true;
        else if( open == '{' && end == '}' )
            return true;
    
        return false;
    }



    bool ispar(string expression){
        
        int len = expression.length(),i,equation_len=0;
        vector<char> equation;
    
        for(i=0;i<len;i++){
    
            if( expression[i] == ')' || expression[i] == ']' || expression[i] == '}' ){
    
            
                if( equation_len > 0 && is_pair_valid(equation[equation_len-1],expression[i]) ){
    
                    equation.pop_back();
                    equation_len--;
                }
                else{
    
                    return false;
                }
    
            }
            else{
    
                equation.push_back(expression[i]);
                equation_len++;
            }
        }
        if(equation_len==0)
            return true;
        return false;
    
    }
};
