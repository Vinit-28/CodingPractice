

// Question Link :; "https://practice.geeksforgeeks.org/problems/smallest-positive-missing-number-1587115621/1#"


// Solution //

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        // Your code here
        int positiveIndex = 0,temp;
        for(int i=0;i<n;i++){

            if( arr[positiveIndex]<= 0  && positiveIndex < i ){
                positiveIndex+=1,i--;
                continue;
            }
            if( arr[i] <= 0 ){
                temp = arr[i], arr[i] = arr[positiveIndex], arr[positiveIndex] = temp;
                positiveIndex += 1;
            }
            
        }
        
        for(int i=positiveIndex; i<n; i++)
            if( ((abs(arr[i])-1)+positiveIndex)<n && arr[((abs(arr[i])-1)+positiveIndex)] > 0 )
                arr[((abs(arr[i])-1)+positiveIndex)] = ( arr[((abs(arr[i])-1)+positiveIndex)] - (arr[((abs(arr[i])-1)+positiveIndex)]*2));

        
        for(int i=positiveIndex;i<n;i++)
            if( arr[i] > 0 )
                return (i-positiveIndex)+1;
 
        return (n-positiveIndex)+1;
    }  
};
