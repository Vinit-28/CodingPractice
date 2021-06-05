

//   Question Link :: "https://practice.geeksforgeeks.org/problems/maximum-value-in-a-bitonic-array3001/1"



// Solution //

class Solution{
public:
	
	int findMaximum(int arr[], int n) {
	    // code here
	    int m=arr[0];
	    
	    for(int i=1;i<n;i++){
	        
	        if(m<arr[i])
	            m=arr[i];
	        else
	            return m;
	    }
	    return m;
	}
};
