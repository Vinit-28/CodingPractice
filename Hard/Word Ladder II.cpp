

// Question Link :: "https://practice.geeksforgeeks.org/problems/word-ladder-ii/1/"


// Solution //

class Solution {
public:

    vector<vector<string>> shortestPaths;
    int minPathSize = INT_MAX;
    
    bool isDifferentFromOneWord(string &s1, string &s2){
        
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
    
    
    void bfs(map<string, vector<string>> &adjList, string &startWord, string &targetWord){
        
        map<string, bool> isVisited;
        
        queue<string> q;
        queue<vector<string>> paths;
        
        q.push(startWord);
        paths.push({startWord});
        
        while(q.empty() == false){
            
            auto node = q.front();
            auto p = paths.front();
            q.pop(), paths.pop();
            
            isVisited[node] = true;
            
            for(auto adj_node: adjList[node]){
                
                if( isVisited[adj_node] == false ){
                    
                    auto tempPath = p;
                    tempPath.push_back(adj_node);
                    
                    q.push(adj_node);
                    paths.push(tempPath);
                    int pathSize = tempPath.size();
                    
                    minPathSize = (adj_node == targetWord)? min(minPathSize, pathSize) : (minPathSize);
                    if( adj_node == targetWord && minPathSize == pathSize )
                        shortestPaths.push_back(tempPath);
                }
            }
        }
    }

    vector<vector<string>> findSequences(string startWord, string targetWord, vector<string>& wordList) {
        // code here
        
        map<string, vector<string>> adjList;
        getAdjList(wordList, adjList);
        map<string, bool> isVisited;
        
        if( adjList[startWord].size()==0 ){
            
            for(int i=0;i<wordList.size();i++)
                if( isDifferentFromOneWord(startWord, wordList[i]) )
                    adjList[startWord].push_back(wordList[i]);
            
        }
        
        isVisited[startWord] = true;
        shortestPaths.clear();
        minPathSize = INT_MAX;
        
        bfs(adjList, startWord, targetWord);
       
        return shortestPaths;
    }
};
