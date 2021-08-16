

// Question Link :: "https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1#"


// Solution //

class Solution{
  public:
  
    int minJumps(int arr[], int n){
        // Your code here
        
        int maxReach = arr[0], steps=arr[0], ans=1;
        
        if( n==1 ) return 0;
        else if( arr[0] == 0 ) return -1;
        else
            for(int i=1;i<n-1;i++){
                steps--;
                maxReach = max(maxReach, arr[i]+i);
                if( steps == 0 ){
                    ans++, steps = (maxReach-i);
                    if( steps==0 )
                        return -1;
                }
            }    
        return ans;
    }
};
