

// Question Link :: "https://practice.geeksforgeeks.org/problems/activity-selection-1587115620/1"


// Solution //

class solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.

    static bool comp(pair<int, int> &a, pair<int,int> &b){
        return a.second < b.second;
    }
    
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        if( n==1 ) return n;
        vector<pair<int, int>> arr;
        int maxJobs=0, lastFinishTime=0;
        
        for(int i=0;i<n;i++)
            arr.push_back({start[i], end[i]});
        
        sort(arr.begin(), arr.end(), comp);
       
        for(auto p : arr)
            if( p.first > lastFinishTime ) maxJobs++, lastFinishTime = p.second;
        return maxJobs;
    }
};