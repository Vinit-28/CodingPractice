

// Question Link :: "https://practice.geeksforgeeks.org/problems/number-of-subsets-with-product-less-than-k/1#"


// Solution //

class Solution {
  public:
  
    int ans;
    int numOfSubsets(int arr[], int N, int K) {
        // code here
        
        vector<int> sub1, sub2;
        ans=0;
        
        makeSubsets(arr, 0, 1, K, N/2, false, sub1);
        makeSubsets(arr, N/2, 1, K, N, false, sub2);
        
        sort(sub2.begin(), sub2.end());
        
        for(int i=0;i<sub1.size();i++)
            ans += combinations(sub2, K/sub1[i]);
        
        return ans;
    }
    
    
    int combinations(vector<int> &sub, int key){
        
        int l = 0, u = sub.size()-1, m=(l+u)/2, lastMatchingIndex=-1;
        
        while(l<=u){
            
            if( sub[m] <= key )
                lastMatchingIndex = m, l=m+1;
            else
                u=m-1;
            
            m=(l+u)/2;
        }
        
        return lastMatchingIndex+1;
    }
    
    void makeSubsets(int arr[], int index, int product, int k, int n, bool flag, vector<int> &sub){
        
        if(product>k)
            return;
            
        if( index==n  ){
            
            if( flag && product<=k )
                sub.push_back(product), ans++;
            return;
        }
        
        makeSubsets(arr, index+1, product, k, n, flag, sub);
        
        makeSubsets(arr, index+1, product*arr[index], k, n, true, sub);
    }
    
};