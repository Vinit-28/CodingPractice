

// Question Link :: "https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#"


// Solution //
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	int platformsRequire = 0, counter=0;
    	
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	
    	for(int a=0,d=0; a<n;){
    	    
    	    if( arr[a] <= dep[d] )
    	        counter+=1,a+=1;
    	    else
    	        counter-=1,d+=1;
    	    
    	    platformsRequire = max(platformsRequire, counter);
    	}
    	
    	return platformsRequire;
    }  
};