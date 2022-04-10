

// Question Link :: "https://leetcode.com/problems/baseball-game/"


// Solution //


class Solution {
public:
    int calPoints(vector<string>& ops) {
        
        stack<int> s;
        int sum = 0;
        for(int i=0;i<ops.size();i++){
            
            if( ops[i] == "C" ){
                s.pop();
            }
            else if( ops[i] == "D" ){
                
                int lastEle = s.top();
                s.push(lastEle*2);
            }
            else if( ops[i] == "+" ){
                
                int lastEle = s.top();
                s.pop();
                int lastSecEle = s.top();
                s.push(lastEle);
                s.push(lastEle+lastSecEle);
            }
            else{
                s.push(stoi(ops[i]));
            }
        }
        
        while( s.empty() == false ) sum += s.top(), s.pop();
        
        return sum;
    }
};