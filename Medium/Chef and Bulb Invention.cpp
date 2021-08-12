

// Question Link :: "https://www.codechef.com/AUG21C/problems/CHFINVNT"


// Solution //
#include <bits/stdc++.h>

using namespace std;


class Solution{


public:
	
	long long int solveProblem(long long int n, long long int k, long long int p){

		n-=1;
		long long int answer=0, h_d, l_d, l_o_h_d, target_rem;
		h_d = (n/k)+1;
		l_d = h_d-1;
		l_o_h_d = (n - ((n/k)*k))+1;
		target_rem = (p%k);

		if( target_rem >= l_o_h_d ){
			answer += (h_d * l_o_h_d);
			target_rem = (target_rem - l_o_h_d)+1;
		}
		else if( target_rem > 0 && target_rem < l_o_h_d ){
			answer += (h_d * target_rem);
			target_rem = 1;
		}

		if( target_rem-1 > 0 )
			answer += (l_d * (target_rem-1));

		return (answer + (p/k) +1);
	}
};


int main(){


	int t;
	cin>>t;

	while(t>0){

		Solution object;
		long long int n, k, p;
		cin>>n>>p>>k;

		cout<<object.solveProblem(n, k, p)<<endl;
		t--;
	}
	return 0;
}