

// Question Link :: "https://practice.geeksforgeeks.org/problems/peak-element/1"


// Solution //

class Solution
{
    public:
    int peakElement(int arr[], int n)
    {
       // Your code here
       int l = 0, u = n-1, mid = (l+u)/2;
       if( n==1 )
        return 0;
       while(l<=u){
           
            if( mid > 0 && mid < n-1 ){
                
                if( arr[mid-1] <= arr[mid] && arr[mid+1] <= arr[mid] )
                    return mid;
                
                else{
                    
                    if( arr[mid-1] > arr[mid+1] )
                        u = mid-1;
                    else
                        l = mid+1;
                }
            }
            
            else if( mid == 0 ){
                if( arr[mid] >= arr[mid+1] )
                    return mid;
                else
                    l = mid + 1;
            }
            
            else if( mid==n-1 ){
                
                if( arr[mid] >= arr[mid-1] )
                    return mid;
                else 
                    u = mid -1;
            }
            
            mid = (l+u)/2;
       }
       
       return -1;
    }
};
