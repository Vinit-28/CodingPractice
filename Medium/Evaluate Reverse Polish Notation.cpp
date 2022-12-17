

// Question Link :: "https://leetcode.com/problems/evaluate-reverse-polish-notation/"


// Solution //

class Solution {
public:
    long long int evaluate(long long int &num1, long long int &num2, string &operation){
        if( operation == "+" ) return num1 + num2;
        else if( operation == "-" ) return num1 - num2;
        else if( operation == "*" ) return num1 * num2;
        return num1 / num2;
    }

    bool isOperand(string &token){
        return (token[0] >= '0' and token[0] <= '9') || token.size() > 1;
    }

    int evalRPN(vector<string>& tokens) {
        
        stack<long long int> s;
        for(auto &token : tokens){
            if( isOperand(token) ){
                s.push(stoi(token));
            }
            else{
                long long int num2 = s.top(); s.pop();
                long long int num1 = s.top(); s.pop();
                s.push(evaluate(num1, num2, token));
            }
        }
        return s.top();
    }
};