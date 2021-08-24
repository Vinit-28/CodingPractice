

// Question Link :: "https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1#"


// Solution //

class Solution{
public:

    int *getReference(int arr1[], int arr2[], int i, int &n, int &m){
        
        if( i<n )
            return &arr1[i];
        return &arr2[i-n];
    }
    
    void recursiveSwap(int arr1[], int arr2[], int &n, int &m, int i, int &gap){
        
        if( i < 0 )
            return;
        
        int *a = getReference(arr1, arr2, i, n, m);
        int *b = getReference(arr1, arr2, i+gap, n, m);
        
        if( *a < *b )
            return;
        
        int temp = *a;
        *a = *b, *b = temp;
        recursiveSwap(arr1, arr2, n, m, i-gap, gap);
    }
    
	void merge(int arr1[], int arr2[], int n, int m) {
	    // code here
	
	    int N = (n+m), gap = N/2;
	    
	    for(; gap >= 1; gap = (gap/2)){
	        
	        for(int i=0;(i+gap)<N;i++){
                
                recursiveSwap(arr1, arr2, n, m, i, gap);
	        }
	    }
	}
};