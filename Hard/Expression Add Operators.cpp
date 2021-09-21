

// Question Link :: "https://leetcode.com/problems/expression-add-operators/"


// Solution //

class Solution {
public:
    vector<string> ans;
    string str;
    int targetNum;
    
    vector<string> addOperators(string num, int target) {
        ans.clear();
        str=num, targetNum=target;
        string expr="";
        recursion("", 0, 0, '0', 0);
        return ans;
    }

    
    void recursion(string expr, long int currNum, long int prevNum, char lastOP, int index){
        
        if( !str[index] ){
            if( currNum == targetNum ) ans.push_back(expr);
            return;
        }
        
        long int num = (int(str[index])-48);
        
        for(int j=index; str[j]; j++){
            
            num = (index==j)? num : (num*10)+(int(str[j])-48);
            
            if( index==0 ){
                recursion(str.substr(index, (j-index)+1), num, 0, '0', j+1);                
            }
            else{
                
                recursion(expr + "+" + str.substr(index, (j-index)+1), currNum + num, currNum, '+', j+1);
                
                recursion(expr + "-" + str.substr(index, (j-index)+1), currNum - num, currNum, '-', j+1);
                
                if( lastOP == '+' || lastOP == '-' ){
                    
                    long int newResult = (prevNum + ((currNum-prevNum)*num));
                    recursion(expr + '*' + str.substr(index, (j-index)+1), newResult, prevNum, lastOP, j+1); 
                }
                else{
                    recursion(expr + '*' + str.substr(index, (j-index)+1), currNum * num, currNum, '*', j+1);
                }
                
            }
            
            if( str[index] == '0' ) break;
        }
    }
};
























