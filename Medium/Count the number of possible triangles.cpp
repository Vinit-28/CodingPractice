

// Question Link :: "https://practice.geeksforgeeks.org/problems/count-possible-triangles-1587115620/1#"



// Solution //

class Solution{
    public:
    //Function to count the number of possible triangles.

    int findNumberOfTriangles(int arr[], int n){
            // code here
        
        int total_ways=0,i;
        sort_arr(arr,n);

        for(i=0;i<n-2;i++){
            
            total_ways+=count_ways(arr,n,i+1,arr[i]);
        }
        
        return total_ways;
    }
    
    void sort_arr(int arr[], int n){
        
        int temp;
        for(int i=0;i<n;i++){
            
            for(int j=i+1;j<n;j++){
                
                if(arr[i]>arr[j]){
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
    
    
    int count_ways(int arr[], int n, int x, int sum){
        
        int y=x+1,ways=0;
        
        while(x<n-1){
            
            if(sum+arr[x] <= arr[y]){
                x+=1;
                y=x+1;
            }
            else{
                
                ways+=1;
                y+=1;
                if( y>=n ){
                    x=x+1;
                    y = x+1;
                }
            }
        }
        return ways;
    }


};
