

// Question Link :: "https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1#"


// Solution //

class Solution 
{
    public:
    
    
    void getUtilities(int arr[], int &n, int &lower, int &upper){
        
        lower = INT_MAX, upper=0;
        for(int i=0;i<n;i++)
            upper += arr[i], lower = min(lower, arr[i]);
    }
    
    
    bool isValid(int arr[], int &n, int m, int &limit){
        
        int sum =0;
        for(int i=0;i<n;i++){
            
            if( (sum + arr[i]) > limit ){
                
                if( m == 1 || arr[i] > limit )
                    return false;
                m--, sum=0;
            }
            sum += arr[i];
        }
        return true;
    }
    
    
    //Function to find minimum number of pages.
    int findPages(int arr[], int n, int m) 
    {
        //code here
        if( m > n || m==0 )
            return -1;
        
        int lower, upper, mid, answer=INT_MAX;
        getUtilities(arr, n, lower, upper);
        mid = (lower+upper)/2;

        while(lower<=upper){

            if( isValid(arr, n, m, mid) )
                upper = mid-1, answer = min(answer, mid);
            else
                lower = mid+1;
            
            mid = (lower+upper)/2;
        }
        return answer;
    }
};
