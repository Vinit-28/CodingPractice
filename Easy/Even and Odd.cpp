

// Question Link :: "https://practice.geeksforgeeks.org/problems/even-and-odd/1"

// Solution //

class Solution {
  public:
    void reArrange(int arr[], int N) {
        // code here
        for(int i=0;i<N;i++){
            
            if( (i%2==0 && arr[i]%2!=0) || (i%2!=0 && arr[i]%2==0) ){
                
                int j=i+1, temp;
                for(;j<N;j++)
                    if( (i%2==0 && arr[j]%2==0) || (i%2!=0 && arr[j]%2!=0) ){
                        temp = arr[j];
                        break;
                    }
                
                arr[j] = arr[i], arr[i]=temp;
            }
        }
    }
};