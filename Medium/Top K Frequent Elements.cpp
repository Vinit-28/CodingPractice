

// Question Link :: "https://leetcode.com/problems/top-k-frequent-elements/"


// Solution //

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> maxHeap;
        map<int, int> hash;
        vector<int> ans;
        
        for(auto &n : nums) hash[n] += 1;
        
        for(auto &p : hash) maxHeap.push({p.second, p.first});
        
        for(int i=0;i<k;i++){
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        
        return ans;
    }
};