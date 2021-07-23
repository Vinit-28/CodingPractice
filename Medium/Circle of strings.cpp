

// Question Link :: "https://practice.geeksforgeeks.org/problems/circle-of-strings4530/1"


// Solution //

class Solution
{
    public:
    void BFS(char node, map<char, vector<char>> &adjList, bool isVisited[]){
        
        queue<char> q;
        q.push(node);
        while(q.empty()==false){
            
            auto n = q.front();
            q.pop();
            isVisited[n-97]=true;
            for(auto n1 : adjList[n])
                if( isVisited[n1-97]==false )
                    q.push(n1), isVisited[n1-97]=true;
        }
    }
    
    void initializeUtils(vector<string> &arr, int in[], int out[], map<char, vector<char>> &adjList){
        
        for(auto s : arr){
            char first = s[0], last = s[s.length()-1];
            adjList[first].push_back(last);
            in[last-97]+=1, out[first-97]+=1;
        }
    }
    
    int isCircle(int n, vector<string> arr)
    {
        // code here
        map<char, vector<char>> adjList;
        int in[26]={0}, out[26]={0};
        bool isVisited[26]={0};
        char node='0';
        
        // Initializing Graph Utilities //
        initializeUtils(arr, in, out, adjList);
        
        // Checking Whether the Graph has an edge or not //
        for(auto n : adjList)
            if( n.second.size() > 0 ){
                node = n.first;
                break;
            }
        
        // If graph does not have any edge //
        if( node=='0' )
            return 0;
    
        // Doing a BFS to find out the different Components of the graph //
        BFS(node, adjList, isVisited);
        
        for(auto n : adjList)
            if( (isVisited[n.first-97]==false && n.second.size()>0) || in[n.first-97]!=out[n.first-97]  )
                return 0;
        return 1;
    }
};