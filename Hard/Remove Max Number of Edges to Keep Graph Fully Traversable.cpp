

// Question Link :: "https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/"


// Solution //

class CustomUnion{
    public: 
        vector<int> parent;
        vector<int> rank;
        int n;
        CustomUnion(int &n){
            this->n = n;
            parent.resize(n+1, -1);
            rank.resize(n+1, 0);
        }

        int findParent(int &node){
            if( parent[node] == -1 )
                return node;
            return parent[node] = findParent(parent[node]);
        }

        bool addEdgeIfNeeded(int &u, int &v){
            int up = findParent(u), vp = findParent(v);
            if( up != vp ){
                if( rank[up] > rank[vp] ) parent[vp] = up;
                else if( rank[vp] > rank[up] ) parent[up] = vp;
                else parent[vp] = up, rank[up] += 1;
                return true;
            }
            return false;
        }

        bool isGraphFullyTraversable(){
            int p = -1;
            for(int i=1;i<=n;i++){
                if( p == -1 )
                    p = findParent(i);
                else if( p != findParent(i) )
                    return false;
            }
            return true;
        }
};



class Solution {
public:
    
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int ans = edges.size();
        CustomUnion alice = CustomUnion(n);
        CustomUnion bob = CustomUnion(n);
        sort(edges.begin(), edges.end(), greater<vector<int>>());

        for(auto &edge : edges){
            int type = edge[0], u = edge[1], v = edge[2];
            if( type == 1 && alice.addEdgeIfNeeded(u, v) ){
                ans -= 1;
            }
            else if ( type == 2 && bob.addEdgeIfNeeded(u, v) ){
                ans -= 1;
            }
            else if( type == 3 ){
                if( alice.addEdgeIfNeeded(u, v) ){
                    bob.addEdgeIfNeeded(u, v);
                    ans -= 1;
                }
            }
        }

        if( !alice.isGraphFullyTraversable() || !bob.isGraphFullyTraversable() )
            return -1;
        return ans;
    }
};