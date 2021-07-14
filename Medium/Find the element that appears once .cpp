

// Question Link :: "https://practice.geeksforgeeks.org/problems/element-appearing-once2552/1#"


// Solution //

class Solution{
public:	

    int findElement(int arr[], int n){
        
        int l = 0, u = n-1, mid = (l+u)/2;
        while(l<=u){
        
            if( mid > 0 && arr[mid] == arr[mid-1] )
                ((mid-1)%2!=0)? (u = mid-2) : (l = mid+1);
            
            else if( mid < n-1 && arr[mid] == arr[mid+1] )
                (((n-mid)-2)%2!=0)? (l = mid+2) : (u = mid-1);

            else{
                
                if( (mid == 0 && arr[mid] != arr[mid+1]) || (mid == n-1 && arr[mid] != arr[mid-1]) )
                    break;
                
                if( mid[arr] != arr[mid-1] && arr[mid] != arr[mid+1] )
                    break;
            }
            mid = (l+u)/2;
        }
        return arr[mid];
    }


	int search(int arr[], int n){
	    //code
	    return findElement(arr, n);
	}
};
