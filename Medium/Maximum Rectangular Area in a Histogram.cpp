

// Question Link :: "https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1#"


// Solution //

class Solution
{
    public:
    vector<long long> nextSmallestElement(long long arr[], int n, char direction){
        // Your code here
        int len = 0,i;
        vector<long long> stack, ans(n);
        i = (direction == 'L')? (n-1) : (0);
        
        while( (direction == 'L' && i>=0) || (direction == 'R' && i<n) ){
            
            if( (direction == 'L' && i == n-1) || ( direction == 'R' && i == 0 ))
                stack.push_back(i),len+=1,ans[i] = -1;
            
            else{
                
                while( len>0 && ( (direction=='L' && arr[stack[len-1]] > arr[i]) || (direction=='R' && arr[stack[len-1]] >= arr[i]) ) )
                    stack.pop_back(),len-=1;
             
                if( len <= 0 ){
                    stack.push_back(i),len+=1,ans[i] = -1;
                    (direction=='L')? (i--):(i++);
                    continue;
                }
                
                ans[i] = stack[len-1],stack.push_back(i),len+=1;
            }
         
            (direction=='L')? (i--):(i++);
            
        }
        return ans;
    }
    
    
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        auto rightSmallest = nextSmallestElement(arr, n, 'L'); // Getting Smallest values on the Right Side by Moving Left Side //
        auto leftSmallest = nextSmallestElement(arr, n, 'R'); // Getting Smallest values on the Leftt Side by Moving Right Side //
        long long int ans  = 0, currVal=0;
       
        for(int i=0;i<n;i++){
            
            currVal = ( leftSmallest[i] == -1 )? ((i+1)*arr[i]) : (abs(i-leftSmallest[i])*arr[i]);
            currVal += ( rightSmallest[i] == -1 )? (abs((n-i)-1)*arr[i]) : (abs((rightSmallest[i]-i)-1)*arr[i]);
    
            ans = max(ans, currVal);
        }
        return ans;
    }
};
