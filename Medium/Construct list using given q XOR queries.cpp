

// Question Link :: "https://practice.geeksforgeeks.org/problems/construct-list-using-given-q-xor-queries/1"


// Solution //

class Solution {
  public:
    vector<int> constructList(vector<vector<int>> Q, int n) {
        // code here
        vector<int> lst;
        int Xor  = 0;
        
        for(int i=n-1;i>=0;i--)
            if( Q[i][0] == 0 )
                lst.push_back( (Q[i][1] xor Xor) );
            else 
                Xor = Xor xor Q[i][1];
        
        lst.push_back(Xor);
        sort(lst.begin(), lst.end());
        return lst;
    }
};
