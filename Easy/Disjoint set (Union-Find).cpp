

// Question Link :: "https://practice.geeksforgeeks.org/problems/disjoint-set-union-find/1"


// Solution //

/*Complete the functions below*/
int find(int A[],int x)
{
       //add code here
       if( A[x] == x )
            return x;
        return find(A, A[x]);
}

void unionSet(int A[],int x,int z)
{
	//add code here.
	int px = find(A, x);
	int pz = find(A, z);
	
	if( px != pz )
	    A[px] = pz;
}
