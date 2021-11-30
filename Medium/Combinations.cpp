

// Question Link :: "https://leetcode.com/problems/combinations/"


// Solution //

class Solution {
public:
    vector<vector<int>> combinations;
    vector<int> comb;
    
    vector<vector<int>> combine(int n, int k) {
        
        combinations.clear();
        comb.clear();
        comb.resize(k);
        rec(0, 1, n, k);
        
        return combinations;
    }
    
    void rec(int index, int num, int &numLimit, int &sizeLimit){
    
        if( index == sizeLimit ){
            combinations.push_back(comb);
            return;
        }
        
        if( num == numLimit+1 ) return;
        
        rec(index, num+1, numLimit, sizeLimit);
        comb[index] = num;
        rec(index+1, num+1, numLimit, sizeLimit);
    }
};