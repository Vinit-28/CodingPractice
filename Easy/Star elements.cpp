

// Question Link :: "https://practice.geeksforgeeks.org/problems/start-elements3447/1"


// Solution //

vector<int> getStarAndSuperStar(int arr[], int n) {
    // code here   
    vector<int> ans, temp={arr[0]};
    int maxEle=INT_MIN, flag=1, i;
    
    for(i=0; i<n; i++){
        
        while( temp.empty()==false && temp.back() <= arr[i] )
            temp.pop_back();
        
        temp.push_back(arr[i]);
        
        if( maxEle < arr[i] )
            maxEle = arr[i], flag = 1;
        
        else if( maxEle == arr[i] )
            flag = 0;
    }
    
    if( flag == 0 )
        maxEle = -1;
    
    ans = {maxEle};
    for(int item : temp)
        ans.push_back(item);
    
    return ans;
}