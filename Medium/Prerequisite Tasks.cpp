

// Question Link :: "https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1"


// Solution //

class Solution{
public:

	bool isPossible_helper(int n, vector<int> adjList[]){
	    
	    vector<bool> isProcessed(n, false), isDependenciesRecorded(n, false);
	    int totalTasksDone = 0;
	    vector<int> stack;
	    
	    stack.push_back(0);
	    
	    while(totalTasksDone < n){
	        
	        auto curr_task = stack.back();
	        
	        if( adjList[curr_task].size() == 0 ){
	            
	            isProcessed[curr_task] = true;
	            isDependenciesRecorded[curr_task] = false;
	            totalTasksDone += 1;
	            stack.pop_back();
	        }
	        
	        else{
	            
                for(auto tasks : adjList[curr_task]){
                
                    if( isDependenciesRecorded[tasks] || curr_task == tasks )
                        return false;
                    
                    if( !isProcessed[tasks] )
                        stack.push_back(tasks);
                }
                
                adjList[curr_task].clear();
                isDependenciesRecorded[curr_task] = true;
	        }
	        
	        if( stack.empty() && totalTasksDone < n ){
	            
	            for(int i=0;i<n;i++)
	                if( !isProcessed[i] ){
	                    stack.push_back(i);
	                    break;
	                }
	        }
	        
	    }
	    
	    return true;
	}
	
	bool isPossible(int n, vector<pair<int, int> >& prerequisites) {
        // Code here
        
        vector<int> adjList[n];
        
        for(auto p : prerequisites){
            
            adjList[p.first].push_back(p.second);
        }
        
        return isPossible_helper(n, adjList);
	}
};