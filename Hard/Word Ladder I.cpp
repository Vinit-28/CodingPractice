

// Question Link :: "https://practice.geeksforgeeks.org/problems/word-ladder/1"


// Solution //

class Solution{
public:
    bool isDifferentFromOneWord(string s1, string s2){
        
        int differ = 0;
        for(int i=0;i<s1.length();i++){
            if( s1[i] != s2[i] )
                differ++;
            
            if( differ>=2 )
                return false;
        }
        return true;
    }
    
    
    void getAdjList(vector<string>& wordList, map<string, vector<string>> &adjList){
        
        int n=wordList.size();
        for(int i=0;i<n; i++){
            
            for(int j=i+1;j<n;j++){
                
                if( isDifferentFromOneWord(wordList[i], wordList[j]) )
                    adjList[wordList[i]].push_back(wordList[j]), adjList[wordList[j]].push_back(wordList[i]);
            }
        }
    }
    
    
    bool bfs(map<string, vector<string>> &adjList, map<string, int> &dist, string &startWord, string &targetWord){
        
        map<string, bool> isVisited;
        
        queue<string> q;
        q.push(startWord);
        dist[startWord] = 1;
        
        while(q.empty() == false){
            
            auto node = q.front();
            q.pop();
            
            isVisited[node] = true;
            
            for(auto adj_node: adjList[node]){
                
                if( isVisited[adj_node] == false ){
                    dist[adj_node] = (dist[adj_node] == 0)? (dist[node]+1) : min(dist[adj_node], dist[node]+1);
                    q.push(adj_node);
                }
                
                if( adj_node == targetWord )
                    return true;
            }
        }
        return false;
    }
    
    
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        
        map<string, vector<string>> adjList;
        map<string, int> dist;
        getAdjList(wordList, adjList);
        
        
        for(int i=0;i<wordList.size();i++)
            if( isDifferentFromOneWord(startWord, wordList[i]) )
                adjList[startWord].push_back(wordList[i]);
        
        if( bfs(adjList, dist, startWord, targetWord) )
            return dist[targetWord];
        return 0;
    }
};
