

// Question Link :: "https://practice.geeksforgeeks.org/problems/check-if-array-contains-contiguous-integers-with-duplicates-allowed2046/1"


// Solution //

class Solution{
    public:
    // Function to check whether the array contains
    // a set of contiguous integers
    bool areElementsContiguous(int arr[], int n)
    {
	    // Complete the function
	    map<int, bool> hash;
	    int mini=INT_MAX;
	    for(int i=0;i<n;i++)
	        hash[arr[i]] = true, mini = min(mini, arr[i]);
	        
	    for(int i=mini,j=0; j<hash.size(); i++,j++) if( !hash[i] ) return false;
	    
	    return true;
    }
};