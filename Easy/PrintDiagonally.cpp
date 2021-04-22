

//  Question Link :: "https://practice.geeksforgeeks.org/problems/print-diagonally4331/1"




// Solution //


class Solution{
	
	public:
	vector<int> downwardDigonal(int N, vector<vector<int>> arr)
	{
		   vector<int> res;
		   
		   int r,c,temp;
		   
		   
		   for(c=0;c<N;c++)
		   {
		       for( r=0,temp=c;temp>=0;temp--,r++)
		            res.push_back(arr[r][temp]);
		   }
		   
		   for(r=1;r<N;r++)
		   {
		       for( temp=r,c=N-1; temp<N;temp++,c--)
		            res.push_back(arr[temp][c]);
		   }
		   return res;
	}

};
