

// Question Link :: "https://practice.geeksforgeeks.org/problems/rearrange-characters4649/1"



// Solution //
class Solution
{
    public:
    string rearrangeString(string str)
    {
        //code here

		map<char, int> counts;
		pair<int,char> temp1,temp2;
		priority_queue<pair<int, char>> heap;
		string result = "";
		int len = str.length();

		for(int i=0;i<len;i++){
			counts[str[i]] += 1;
		}

		for(auto p : counts){

			temp1 = {p.second, p.first};

			heap.push(temp1);

		}
		
		for(int i=0;i<len;){

			if( heap.size() >= 2 ){

				temp1 = heap.top();
				heap.pop();

				temp2 = heap.top();
				heap.pop();

				result += temp1.second;
				result += temp2.second;

				temp1.first-=1;
				temp2.first-=1;

				if( temp1.first > 0 )
					heap.push(temp1);
				if( temp2.first > 0 )
					heap.push(temp2); 

				i+=2;

			}

			else if( heap.size() == 1 && i == len-1 ){

				result += heap.top().second;
				i+=1;
			}
			else{

				return "-1";
			}

			// cout<<result<<endl;
			
		}
		
		return result;
	}
    
};