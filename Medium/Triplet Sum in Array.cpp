

// Question Link :: ""https://practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1# 



// Solution //

class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int arr[], int n, int x)
    {
        //Your Code Here
        sort_arr(arr,n);
        int sum,i,left,right,temp;
        
        for(i=0;i<n;i++){
            
            sum = arr[i];
            left = i+1;
            right = n-1;
            
            while (left<right){
                
                temp = sum + arr[left] + arr[right];
                
                if(temp == x)
                    return true;
                else if(temp<x)
                    left+=1;
                else
                    right-=1;
                    
            }
        }
        return false;
    }
    
    
    
    void sort_arr(int arr[], int n){
        
        int temp;
        for(int i=0;i<n;i++){
            
            for(int j=i+1;j<n;j++){
                if(arr[i] > arr[j]){
                    temp = arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                }
            }
        }
    }

};
