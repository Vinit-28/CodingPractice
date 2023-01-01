

// Question Link :: "https://leetcode.com/problems/partition-string-into-substrings-with-values-at-most-k/description/"


// Solution //
class Solution {
public:
    long long int getNum(long long int n, char c){
        return (n*10)+(c-48);
    }
    
    int minimumPartition(string s, int k) {
        long long int num=0, ans = 0;
        for(auto &d : s){
            if( getNum(num, d) <= k ){
                num = num*10 + (d-48);
            }
            else{
                if( (d-48) > k ) return -1;
                num = d-48, ans += 1;
            }
        }
        return ans+1;
    }
};