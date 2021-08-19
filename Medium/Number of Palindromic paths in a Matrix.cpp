

// Question Link :: "https://practice.geeksforgeeks.org/problems/number-of-palindromic-paths-in-a-matrix0819/1"


// Solution //

class Solution {
  public:
    
    int n, m;
    long long int mod = 1000000007;

    int countPalindromicPaths(vector<vector<char>> &matrix){
        // Code here
        n=matrix.size(), m=matrix[0].size();
        map<pair<pair<int, int>, pair<int,int>>,  long long int> hash;
        return traverse(0, 0, n-1, m-1, matrix, hash);
    }
    
    bool isValid(int &front_i, int &front_j, int &back_i, int &back_j){
        
        if( front_i >= n || front_j >= m || back_i < 0 || back_j < 0)
            return false;
        return true;
    }
    
    long long int add(long long int a, long long int b){
        
        return (( (a%mod) + (b%mod) )%mod);
    }
    

    int traverse( int front_i, int front_j, int back_i, int back_j, vector<vector<char>> &mat, map<pair<pair<int, int>, pair<int,int>>,  long long int> &hash){
        
        if( isValid(front_i, front_j, back_i, back_j)==false || mat[front_i][front_j] != mat[back_i][back_j] )
            return 0;
        
        if( hash.find({ {front_i, front_j}, {back_i, back_j} }) != hash.end() )
            return hash[{ {front_i, front_j}, {back_i, back_j} }];
            
        int diffx = (back_i - front_i), diffy = (back_j - front_j);
        
        if( (front_i == back_i && front_j == back_j) || (diffx==1 && diffy==0) || (diffx==0 && diffy==1) )
            return hash[ { {front_i, front_j}, {back_i, back_j} } ] = 1;
        
        int res = 0;

        res = add(res, traverse(front_i+1, front_j, back_i-1, back_j, mat, hash) );
        
        res = add(res, traverse(front_i+1, front_j, back_i, back_j-1, mat, hash) );
 
        res = add(res, traverse(front_i, front_j+1, back_i-1, back_j, mat, hash) );

        res = add(res, traverse(front_i, front_j+1, back_i, back_j-1, mat, hash) );

        return hash[ { {front_i, front_j}, {back_i, back_j} } ]=res;

    }
};
