

// Question Link :: "https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1#"


// Solution //

class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int ans = solveProblem(arr1, arr2, n, m, k);
        if( ans!=-1 ) return ans;
        // cout<<ans<<endl;
        return solveProblem(arr2, arr1, m, n, k);
    }
    
    int solveProblem(int arr1[], int arr2[], int n, int m, int &k){
        
        int l=0, u=n-1, mid=(l+u)/2;

        while(l<=u){
            
            int temp = doBinarySearch(arr2, arr1[mid], m, k, mid);
            // if( temp==-1 ) u=mid-1;
            if( (temp+mid) == (k-1) ) return arr1[mid];
            else if( (temp+mid) < (k-1) ) l = mid+1;
            else u = mid-1;
            
            mid = (l+u)/2;
            
        }
        return -1;
    }
    
    int doBinarySearch(int arr[], int &key, int &m, int &k, int diff){
        
        int l=0, u=m-1, mid=(l+u)/2;
        int possibleAns=m;
        while(l<=u){
            
            if( arr[mid] == key ){
                
                if( (mid+diff) == k-1 ) return mid;
                else if( (mid+diff) < k-1 ) l = mid+1;
                else u = mid-1;
            }
            
            else if( arr[mid] > key ) possibleAns = mid, u=mid-1;
            else l=mid+1;
            
            mid = (l+u)/2;
        }
        return possibleAns;
    }
};
