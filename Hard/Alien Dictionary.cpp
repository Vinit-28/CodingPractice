

// Question Link :: "https://practice.geeksforgeeks.org/problems/alien-dictionary/1"


// Solution //

class Solution{
    public:
    
    void BuildAdjacencyList(vector<vector<int>> &adjList, string dict[], int n){
        
        for(int i=0;i<n-1;i++){
            
            string str1 = dict[i], str2 = dict[i+1];
            for(int j=0,k=0; ( str1[j] && str2[k] ); j++,k++){
                
                if( str1[j] != str2[k] ){
                    
                    adjList[int(str1[j])-97].push_back(int(str2[k])-97);
                    break;
                }
            }
        }
        
    }
    
    void dfs(vector<vector<int>> &adjList, int node, vector<bool> &isVisited, string &alienSequence){
        
        isVisited[node]=true;
        for(auto vertex : adjList[node]){
            
            if( isVisited[vertex] == false ){
                dfs(adjList, vertex, isVisited, alienSequence);
            }
        }
        
        alienSequence += char(node+97);
    }
    
    string findOrder(string dict[], int n, int k) {
        
        //code here
        vector<vector<int>> adjList(k);
        vector<bool> isVisited(k,false);
        string alienSequence="";
        
        BuildAdjacencyList(adjList, dict, n);
        
        for(int i=0;i<k;i++){
            
            if( isVisited[i] == false )
                dfs(adjList, i, isVisited, alienSequence);
        }
        
        reverse(alienSequence.begin(), alienSequence.end());
        return alienSequence;
    }
};
