

// Question Link :: "https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/1#"


// Solution //

class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	    long long mini=arr[0], maxi=arr[0], ans=arr[0];
	    
	    for(int i=1;i<n;i++){
	        
	        long long int a = mini*arr[i], b = maxi*arr[i], c = arr[i];
	        
	        maxi = max(max(a, b), c);
	        mini = min(min(a, b), c);
	        
	        ans = max(max(mini, maxi), ans);
	    }
	    return ans;
	}
};