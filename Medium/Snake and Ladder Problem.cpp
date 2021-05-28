

//   Question Link :: "https://practice.geeksforgeeks.org/problems/snake-and-ladder-problem4816/1"



// Solution //


class Solution{
public:
    
    vector<int> snakes;
    vector<pair<int, int>> ladders;
    int ladd_len, sna_len, ultimate_target=30;
    
    int min_moves = -1;
    
    int minThrow(int n, int arr[]){
        // code here
        snakes ={};
        ladders = {};
        
        get_snakes_ladders_pos(arr,n*2);
        
        sort(ladders.begin(),ladders.end());
        
        ladd_len = ladders.size();
        sna_len = snakes.size();
        
        min_moves=-1;
        
        
        rec(0,1,0);
        return min_moves;
        
    }
    
    
    
    
    
    void rec(int moves, int curr, int ladd_index){
        

        if(curr == ultimate_target){
            
            if(min_moves == -1){
                min_moves = moves;
            }
            else{
                min_moves = min(min_moves,moves);
            }
            
            return;
        }
        
        for( ladd_index; ladd_index<ladd_len; ladd_index+=1 ){
            
            if(curr < ladders[ladd_index].first){
                
                rec( ( moves + get_moves(ladders[ladd_index].first, curr) ), ladders[ladd_index].second ,ladd_index+1);
            }
            
        }
        
        if(curr < ultimate_target){
            
            rec(moves+get_moves(ultimate_target, curr), ultimate_target ,ladd_len);
        }
        
    }
    
    
    
    int get_moves(int target, int curr){
        
        int moves=0,dice;
        
        while(curr < target){
            
            dice =6;
            
            if((target-curr) <= 6){
                
                return moves+1;
            }
            
            
            while(true){
                
                if(is_snake_pos(curr+dice) == false)
                    break;
                dice-=1;
            }
            
            curr+=dice;
            moves+=1;
        }
        
        return moves;
        
    }
    
    
    
    bool is_snake_pos(int pos){
        
        for(int i=0;i<snakes.size();i++){
            if(pos==snakes[i])
                return true;
        }
        false;
    }
    
    
    
    void get_snakes_ladders_pos(int mat[], int n){
        
        for(int i=0;i<n;i+=2){
      
            if(mat[i] > mat[i+1]){
                snakes.push_back(mat[i]);
            }
            else{
                
                ladders.push_back({mat[i],mat[i+1]});
            }
            
        }
        
    }
    
};

