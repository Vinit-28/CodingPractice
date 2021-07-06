

// Question Link :: "https://practice.geeksforgeeks.org/problems/the-painters-partition-problem1535/1"


// Solution //

class Solution
{
  public:
    
    long long int getMaxTimeLimit(int arr[], int n, long long int &maxElement){
        
        long long int sum=0;
        for(int i=0;i<n;sum+=arr[i], i++)
            if( maxElement < arr[i] )
                maxElement = arr[i];
        return sum;
    }
    
    bool isPossible(int arr[], int &n, long long int &timeLimit, long long int &timeTaken, int k){
        
        long long int currTime=0;
        for(int i=0;i<n;i++){
            
            if( (currTime+arr[i]) > timeLimit ){
                
                timeTaken = max(timeTaken,currTime);
                currTime = arr[i];
                k-=1;
                
                if( k<=0 || currTime > timeLimit )
                    return false;
            }
            else
                currTime += arr[i];
        }
        timeTaken = max(timeTaken,currTime);
        return true;
    }
    
    long long minTime(int arr[], int n, int k){
        // code here
        if( k>=n )
            return *max_element(arr,arr+n);
            
        long long int l = arr[0], u, m, minTime = __LONG_MAX__;
        
        u = getMaxTimeLimit(arr,n,l);
        m = (l+u)/2;
        
        while( l<=u ){
             
            long long int timeTaken=0;
            if( isPossible(arr, n, m, timeTaken, k) )
                minTime = min(minTime, timeTaken), u = timeTaken-1;
            else
                l = m+1;
            m = (l+u)/2;
        }
        return minTime;
    }
};
