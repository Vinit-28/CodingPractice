

// Question Link :: "https://practice.geeksforgeeks.org/problems/count-the-elements1529/1"


// Solution //

long long int getMax(vector<long long> &vec){
    long long int m = vec[0];
    for(auto ele : vec)
        if( m < ele )
            m = ele;
    return m;
}


vector<long long> find(vector<long long> a,vector<long long> b,vector<long long> q) {
    
    vector<long long> ans;
    map<long long int, long long int> hash;
    auto m = getMax(a);
    
    for(int i=0;i<b.size();i++)
        hash[b[i]] += 1;
    
    for(long long int i=0;i<=m;i++)
        if( i!=0 )
            hash[i] += hash[i-1];
    
    for(auto query:q)
        ans.push_back(hash[a[query]]);
    
    return ans;
}