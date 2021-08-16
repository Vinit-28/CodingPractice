

// Question Link :: "https://practice.geeksforgeeks.org/problems/median-of-2-sorted-arrays-of-different-sizes/1"


// Solution //

double MedianOfArrays(vector<int>& nums1, vector<int>& nums2)
{
    // Your code goes here
    int n = nums1.size(), m = nums2.size();
    if( (m+n) == 0 )
        return 0;
    vector<int> arr(n+m, 0);
    int i=0,j=0,index=0;
    double ans = 0;
    
    for(i=j=0; (i<n||j<m);index++){
        
        if( (i<n && j>=m) || (i<n && j<m && nums1[i] < nums2[j]) )
            arr[index] = nums1[i], i++;
        else 
            arr[index] = nums2[j], j++;
    }
    
    if( (m+n)%2 == 0 ){
        int index1 = (m+n)/2, index2 = index1-1;
        double div = 2.0;
        ans = (arr[index1] + arr[index2])/div;
    }
    else
        ans = (arr[(m+n)/2]);

    return ans;
}
