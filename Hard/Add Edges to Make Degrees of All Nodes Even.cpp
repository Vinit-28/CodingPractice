

// Question Link :: "https://leetcode.com/problems/add-edges-to-make-degrees-of-all-nodes-even/description/"


// Solution //
class Solution {
public:

    bool isPossible(int n, vector<vector<int>>& edges) { 
        vector<int> odds, even;
        map<int, map<int, int>> g;
        // Making the graph //
        for(auto edge : edges){
            g[edge[0]][edge[1]] = g[edge[1]][edge[0]] = 1;
        }
        // Finding the nodes having odd & even edges //
        for(int i=1;i<=n;i++){
            if( (g[i].size())&1 ) odds.push_back(i);
            else even.push_back(i);
        }
        int size = odds.size();

        // If we have 1 or 3 odd nodes then answer will be false //
        if( size == 1 || size == 3 ) return false;
        else if( size == 2 ){
            // Finding an even node that can be placed between 2 odd nodes //
            for(auto &e_n : even){
                if( g[e_n][odds[0]] == 0 && g[e_n][odds[1]] == 0 ) return true;
            }
            // Or if the 2 odd nodes can connect with each other //
            return g[odds[0]][odds[1]] == 0;
        }
        else if( size == 4 ){
            // 1st node with 2nd node && 3rd node with 4th node //
            if( g[odds[0]][odds[1]] == 0 && g[odds[2]][odds[3]] == 0 ) return true;
            
            // 1st node with 3rd node && 2nd node with 4th node //
            else if( g[odds[0]][odds[2]] == 0 && g[odds[1]][odds[3]] == 0 ) return true;
            
            // 1st node with 4th node && 2nd node with 3rd node //
            else if( g[odds[0]][odds[3]] == 0 && g[odds[1]][odds[2]] == 0 ) return true;
        }

        // If the graph doest not contain any odd node //
        return size == 0;
    }
};