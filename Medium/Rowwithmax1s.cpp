

//  Question Link :: "https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1"



// Solution //

class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int max_1 = 0,curr_1=0,i,j,r_index=-1;
	    
	    for ( i=0;i<n;i++){
	        
	        for ( curr_1=0,j=0;j<m;j++){
	            
	            if ( arr[i][j] == 1){
	                curr_1+=1;
	            }
	            else if ( curr_1 >0)
	                break;
	        }
	        if (max_1 < curr_1)
	            r_index = i,max_1=curr_1;
	    }
	    return r_index;
	}

};