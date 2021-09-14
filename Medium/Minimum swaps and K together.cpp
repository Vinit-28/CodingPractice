

// Question Link :: "https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together4847/1"


// Solution //

int minSwap(int arr[], int n, int k) {
    // Complet the function
    
    int totalK=0, ans=0, bad=0;
    
    for(int i=0;i<n;i++) if( arr[i] <= k ) totalK++;
    
    for(int i=0;i<totalK;i++) if( arr[i] > k ) bad++;
    
    ans = bad;
    
    for(int i=1,j=totalK; j<n; j++,i++){
        
        if( arr[i-1] > k ) bad--;
        
        if( arr[j] > k ) bad++;
        
        ans = min(ans, bad);
    }
    return ans;
}
