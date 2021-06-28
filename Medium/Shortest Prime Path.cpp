

// Question Link :: "https://practice.geeksforgeeks.org/problems/2b9978653b4d905d12c04387a60e16464ef40733/1#"


// Solution //

class Solution{   
    public:
        
        vector<bool> prime;
        
        // Generating Prime Numbers List //
        void generate_prime_list(){
            
            if( prime.size() < 10000 ){
                
                prime = vector<bool>(10000,false);
                
                for(int i=1001; i<10000; i++){
                    
                    if(is_prime(i))
                        prime[i] = true;
                }
            }
        }
        
        
        // Determining Number is Prime or Not //
        bool is_prime(int num){
            
            for(int i = 2; i <= (num/2); i++)
                if(num%i==0)
                    return false;
            
            return true;
        }
        
        
        // Generating New Numbers from an Existing Number //
        vector<int> generate_new_numbers(int curr_num){
            
            string num = to_string(curr_num);
            vector<int> numbers;
            for(int i=0;i<num.length();i++){
                
                for(int j=48; j<58; j++){
                    
                    if( char(j) != num[i] && (! ( j==0 && i==0 ) ) ){
                        
                        string temp = num;
                        temp[i] = char(j);
                        numbers.push_back(stoi(temp));
                    }
                }
            }
            return numbers;
        }
        
        
        // Traversing Over 4 Digit Prime Numbers //
        int Breadth_First_Search(int &source, int &destination){
            
             vector<int> distance(10000,-1), is_visited(10000,0);
             queue<int> nodes;
             int curr_num;
             
             nodes.push(source);
             distance[source]=0;
             
             while(nodes.empty()==false && distance[destination] == -1){
                 
                 curr_num = nodes.front();
                 nodes.pop();
                 is_visited[curr_num] = 1;
                 
                 for(auto new_num : generate_new_numbers(curr_num)){
                     
                     if( prime[new_num] && distance[new_num] == -1 ){
                         
                         nodes.push(new_num);
                         distance[new_num] = distance[curr_num]+1;
                     }
                 }
                 
             }
             return distance[destination];
        }
        

        // Solving the Problem //
        int solve(int Num1,int Num2)
        {   
          //code here
          generate_prime_list();
          return Breadth_First_Search(Num1, Num2);
        }
};

