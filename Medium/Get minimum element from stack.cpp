

// Question Link :: "https://practice.geeksforgeeks.org/problems/get-minimum-element-from-stack/1#"


// Solution //

/*returns min element from stack*/
int _stack :: getMin()
{
   //Your code here
   return (!s.size())? -1 : minEle;
}

/*returns poped element from stack*/
int _stack ::pop()
{
   //Your code here
   if( s.size()==0 )
        return -1;

    int t = s.top(), ret = t;
    s.pop();
    if( t < minEle )
        ret = minEle, minEle = (2*minEle)-t;
    return ret;
}

/*push element x into the stack*/
void _stack::push(int x)
{
   //Your code here
   
    if( s.size()==0 )
        minEle = x, s.push(x);
    else if( x < minEle )
        s.push((2*x)-minEle), minEle=x;
    else
        s.push(x);
}
