

// Question Link :: "https://practice.geeksforgeeks.org/problems/exit-point-in-a-matrix0905/1"


// Solution //

class Solution{
public:
    vector<int> FindExitPoint(vector<vector<int>>&matrix){
		// Code here
        // East -> 0, South -> 1, West -> 2, North -> 3 // 		
		int dir = 0, i=0, j=0, r,c;
		int m = matrix.size(), n = matrix[m-1].size();
		while(i>=0 && i<m && j>=0 && j<n){
		    
		    dir = ((dir+matrix[i][j])%4);
		    matrix[i][j] = 0, r=i, c=j;
		    (dir==0)? (j++) : (dir==1)? (i++) : (dir==2)? (j--) : (dir==3)? (i--) : 0;
		}
		return {r,c};
    }
};