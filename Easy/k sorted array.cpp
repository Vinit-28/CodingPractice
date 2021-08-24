

// Question Link :: "https://practice.geeksforgeeks.org/problems/k-sorted-array1610/1#"


// Solution //

class Solution {
  public:
  
    int getIndex(int arr[], int ele, int n){
        
        int l=0, u=n-1, m=(l+u)/2;
        
        while(l<=u){
            
            if( arr[m] > ele )
                u = m-1;
            else if( arr[m] < ele )
                l = m+1;
            else
                return m;
            
            m = (l+u)/2;
        }
        return -1;
    }
    
    string isKSortedArray(int arr[], int n, int k)
    {
        //code here.
        int dup[n];
        for(int i=0;i<n;i++) dup[i] = arr[i];
        
        sort(dup, dup+n);
        
        for(int i=0;i<n;i++)
            if( abs(i - getIndex(dup, arr[i], n)) > k )
                return "No";
                
        return "Yes";
    }
};