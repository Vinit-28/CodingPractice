

// Question Link :: "https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1"


// Solution //

class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    
    void applyMergeProcedure(long long arr[], long long l1, long long h1, long long l2, long long h2, long long int &ans){
        
        long long temp[ ((h1-l1)+1) + ((h2-l2)+1) ], index=0, tempIndex=l1;
        
        while(l1<=h1 || l2<=h2){
            
            if( l1<=h1 && l2<=h2 ){
                (arr[l1] > arr[l2])? (ans+=((h1-l1)+1), temp[index]=arr[l2], l2++) : (temp[index]=arr[l1], l1++);
                index++;
            }
            else
                (l1 <= h1)? (temp[index]=arr[l1], l1++,index++) : (temp[index]=arr[l2], l2++, index++);
        }
        
        for(int i=0; i<index; tempIndex++,i++)
            arr[tempIndex]=temp[i];
    }
    
    
    void mergeSort(long long arr[], long long  l, long long h, long long int &ans){
        
        if( l<h ){
            
            mergeSort(arr, l, (l+h)/2, ans);
            
            mergeSort(arr, ((l+h)/2)+1, h, ans);
            
            applyMergeProcedure(arr, l, ((l+h)/2), ((l+h)/2)+1, h, ans);
        }
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long int ans=0;
        mergeSort(arr, 0, N-1, ans);
        return ans;
    }

};