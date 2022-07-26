

// Question Link :: "https://leetcode.com/problems/rotate-image/"


// Solution //

class Solution {
public:
    
    void swap(int &a, int &b){
        int temp = a;
        a = b, b = temp;
    }
    
    void reverseColumn(vector<vector<int>>& mat, int &n, int &col){
        
        int i=0, j=n-1;
        while(i<=j){
            swap(mat[i][col], mat[j][col]);
            i+=1, j-=1;
        }
    }
    
    void swapColumns(vector<vector<int>>& mat, int &indexStart, int &indexEnd, int &n, int till){
        
        int i=0, j=n-1;
        while(till){
            swap(mat[i][indexStart], mat[n-indexEnd][j]);
            till-=1, i+=1, j-=1;
        }
    }
    
    void rotate(vector<vector<int>>& mat) {
        
        int n=mat.size(), till=n, indexStart=0, indexEnd=1;
        while(till){
            
            swapColumns(mat, indexStart, indexEnd, n, till);
            reverseColumn(mat, n, indexStart);
            till-=1, indexStart+=1, indexEnd+=1;
        }
    }
};