

// Question Link :: "https://leetcode.com/problems/maximum-xor-with-an-element-from-array/"


// Solution //

class Solution {
public:
    
    class Node{
      
        public:
            int bit;
            Node *arr[2] = {NULL, NULL};
    };
    
    
    static bool comparison(vector<int> &a, vector<int> &b){
        
        return (a[1] < b[1]);
    }
    
    
    void insert(int num, Node *node){
        
        for(int i=31;i>=0;i--){
            int bit = (num >> i)&1;
            if( node->arr[bit] == NULL ){
                node->arr[bit] = new Node;
                node->arr[bit]->bit = bit;
            }
            node = node->arr[bit];
        }
    }
    
    
    int getMaxXor(int num, Node *node){
        
        int maxXor = 0;
        for(int i=31;i>=0;i--){
            int bit = (num >> i)&1;
            if( node->arr[!(bit)] != NULL ){
                maxXor += (1<<i);
                node = node->arr[!(bit)];
            }
            else
                node = node->arr[bit];
        }
        return maxXor;
    }
    
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        
        int index=0, qSize = queries.size(), numSize = nums.size();
        vector<int> answer(qSize, -1);
        Node *root = new Node;
        
        for(int i=0;i<qSize;i++)
            queries[i].push_back(i);
        
        sort(queries.begin(), queries.end(), comparison);
        sort(nums.begin(), nums.end());
    
        for(auto q : queries){
            
            while( index < numSize && nums[index] <= q[1])
                insert(nums[index], root), index++;
    
            if( index>0 )
                answer[q[2]] = getMaxXor(q[0], root);
        }
        
        return answer;
    }
};