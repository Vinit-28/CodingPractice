

// Question Link :: "https://practice.geeksforgeeks.org/problems/container-with-most-water0535/1"



// Solution //

long long maxArea(long long arr[], int n)
{
    // Your code goes here

    long long int maxans = 0;
    
    for(int i=0;i<n;i++){
        
        int j = 0; 
        while(arr[j] < arr[i] && j<i)
            j++;
        
        maxans = max(maxans, (abs(i-j)*arr[i]));
        j = n-1;
        
        while(arr[j] < arr[i] && j>i)
            j--;
        
        maxans = max(maxans, (abs(i-j)*arr[i]));
    }
    
    return maxans;
}
