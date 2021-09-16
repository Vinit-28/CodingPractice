

// Question Link :: "https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1"


// Solution //

class Solution
{
    public:
    
    static bool comp(pair<int, int> &a, pair<int, int> &b){
        return (a.second < b.second);
    }
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int, int>> lst;
        int ans=1, index=0;
        for(int i=0;i<n;i++) lst.push_back({start[i], end[i]});
        
        sort(lst.begin(), lst.end(), comp);
  
        for(int i=1;i<n;i++) if( lst[i].first > lst[index].second ) ans++, index=i;
        return ans;
    }
};
