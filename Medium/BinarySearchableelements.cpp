


//   Qusetion Link :: "https://practice.geeksforgeeks.org/problems/binary-searchable-elements/1"



// Solution //

class Solution {
  public:
    
    int binarySearchable(int arr[], int n) {
        // code here
        bool valid[n];
        int curr_max = arr[0],i,j;
        
        for(i=1;i<n;i++){
            
            if(arr[i]>=curr_max){
                valid[i] = true;
                curr_max = arr[i];
            }
            else{
                valid[i] = false;
            }
        }
        
        valid[0] = valid[1];
        
        int count=0,curr_min = arr[n-1];
        
        for(i=n-2;i>=0;i--){
            
            if(arr[i] <= curr_min){
                
                (valid[i])? (count++) : (count);
                valid[i] = true;
                curr_min = arr[i];
            }
            else{
                valid[i]=false;
            }
            
        }
        
        if(valid[n-2]==true)
            count+=1;
        return count;
        
    }
    
};