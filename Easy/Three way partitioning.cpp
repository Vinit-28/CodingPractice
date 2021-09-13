

// Question Link :: "https://practice.geeksforgeeks.org/problems/three-way-partitioning/1"


// Solution //

class Solution{   
public:
    //Function to partition the array around the range such 
    //that array is divided into three parts.
    
    void doSwap(int &a, int &b){
        
        int temp = a;
        a=b, b=temp;
    }
    
    
    void threeWayPartition(vector<int>& arr,int a, int b)
    {
        // code here 
        int index=0, n=arr.size();
        
        for(int i=0,k=0;i<n;i++){
            
            if( arr[i] >= a ){
                while(k<n && arr[k] >= a) k++;
                
                if( k >= n ) goto out;
                else doSwap(arr[i],arr[k]), index++;
            }
            else k++;
        }
        out:
        
        for(int i=index, k=index; i<n ;i++){
            
            if( arr[i] > b ){
                while(k<n && arr[k] > b ) k++;
                
                if( k >= n ) return;
                else doSwap(arr[i],arr[k]), index++;
            }
            else k++;
        }
    }
};