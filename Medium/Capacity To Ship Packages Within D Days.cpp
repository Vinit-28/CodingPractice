

// Question Link :: "https://practice.geeksforgeeks.org/problems/capacity-to-ship-packages-within-d-days/1"


// Solution //
class Solution {
  public:
    
    int getSum(int arr[], int n){
        int sum = 0;
        for(int i=0;i<n;i++)
            sum+=arr[i];
        return sum;
    }
    
    bool isPossible(int arr[], int n, int limit, int d){
        for(int i=0,sum = 0; i<n; sum+=arr[i],i++){
            
            if( sum+arr[i] > limit ){
                
                if( arr[i] > limit || d==1 )
                    return false;
                sum = 0, d--;
            }
        }
        return true;
    }
    
    int leastWeightCapacity(int arr[], int n, int d) {
        // code here
        int upper = getSum(arr,n), lower = *max_element(arr, arr+n), ans = 0;
        if( d <= 1 )
            return upper;
        else if( n == d )
            return lower;
        else{
            int mid = (lower+upper)/2;
            while(lower<=upper){
                
                if( isPossible(arr, n, mid, d) )
                    ans = mid, upper = mid-1;
                else
                    lower = mid+1;
                mid = (lower+upper)/2;
            }
        }
        return ans;
    }
};