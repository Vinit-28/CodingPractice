

// Question Link :: "https://practice.geeksforgeeks.org/problems/array-subset-of-another-array2317/1"


// Solution //

string isSubset(int a1[], int a2[], int n, int m) {
    
    map<int, bool> hash;
    for(int i=0;i<n;i++) hash[a1[i]]=true;
    
    for(int i=0;i<m;i++) if( !hash[a2[i]] ) return "No";
    return "Yes";
}