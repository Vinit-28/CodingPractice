

// Question Link :: "https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1"


// Solution //

vector<long long> printFirstNegativeInteger(long long int arr[], long long int n, long long int k){
    
    queue<long long int> q, indexes;
    vector<long long int> ans;
    long long int i = 0, counter = 1, start = 0;
    
    for(i=0; i<n; i++,counter++){
        
        if( arr[i] < 0 )
            q.push(arr[i]), indexes.push(i);
        
        if( counter == k ){
            
            if( q.size() != 0 )
                ans.push_back(q.front());
            else
                ans.push_back(0);
            
            while( indexes.empty()==false && (start+1)>indexes.front() )
                q.pop(), indexes.pop();
            
            counter-=1;
            start++;
        }
    }
    
    return ans;
}