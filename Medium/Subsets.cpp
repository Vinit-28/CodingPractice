

//   Question Link :: "https://practice.geeksforgeeks.org/problems/subsets-1613027340/1"





// Solution //


class Solution
{
    public:
    vector<vector<int>> subset;
    vector<int> arr;
    int n;
    vector<vector<int> > subsets(vector<int>& A)
    {
        arr = A;
        subset.clear();
        n = A.size();
        rec(0,{});
        sort(subset.begin(),subset.end());
        return subset;
        //code here
    }
    
    void rec(int i, vector<int> vec){
        
        subset.push_back(vec);
        for(i;i<n;i++){
            vec.push_back(arr[i]);
            rec(i+1,vec);
            vec.pop_back();
        }
        
    }
};
