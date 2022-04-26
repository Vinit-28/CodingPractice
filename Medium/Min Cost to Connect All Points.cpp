

// Question Link :: "https://leetcode.com/problems/min-cost-to-connect-all-points/"


// Solution //

class Solution {
public:
    
    int getDistance(int &x1, int &y1, int &x2, int &y2){
        return (abs(x1-x2) + abs(y1-y2));
    }
    
    void findPaths(priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> &minHeap, vector<vector<int>> &points, bool isVisited[], int currNode){
        
        for(int i=0;i<points.size();i++){
            
            if( i != currNode && isVisited[i] == 0 ){
                int dist = getDistance(points[currNode][0], points[currNode][1], points[i][0], points[i][1]);
                minHeap.push({dist, i});
            }
        }
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        // Min heap will store pair<int, int> {total cost till this node, node}         
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        int ans = 0, nodes = points.size(), totalVisitedNodes = 0;
        bool isVisited[nodes];
        memset(isVisited, 0, sizeof(isVisited));
        minHeap.push({0,0});
        
        while( totalVisitedNodes < nodes ){
            
            while( minHeap.size() && isVisited[minHeap.top().second] ) minHeap.pop();
            
            auto p = minHeap.top();
            minHeap.pop();
            ans += p.first;
            isVisited[p.second] = true;
            totalVisitedNodes += 1;
            findPaths(minHeap, points, isVisited, p.second);
        }
        
        
        return ans;
    }
};