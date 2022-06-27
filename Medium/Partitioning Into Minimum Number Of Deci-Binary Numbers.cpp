

// Question Link :: "https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/"


// Solution //

class Solution {
public:
    int minPartitions(string n) {
        
        int count=0;
        for(auto &ch : n){
            count = max(count, ch - '0');
        }
        return count;
    }
};