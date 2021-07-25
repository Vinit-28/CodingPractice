

// Question Link :: "https://practice.geeksforgeeks.org/problems/does-robot-moves-circular0414/1"


// Solution //

string isCircular(string path){
    //complete the function here
    int x=0, y=0, currDir=0;
    // Direction Code = East : 0, North : 1, West = 2, South : 3 //
    // directions[][2] = {{'N','S'}, {'W', 'E'}, {'S', 'N'}, {'E', 'W'}} //
    int directions[][2] = {{1, 3}, {2, 0}, {3, 1}, {0, 2}};
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    
    for(int i=0;i<path.length();i++){
     
        if( path[i]=='G' )
            x+=dx[currDir], y+=dy[currDir];
        else
            currDir = (path[i]=='L')? directions[currDir][0] : directions[currDir][1];
    }
    if( x==0 && y==0 )
        return "Circular";
    return "Not Circular";
}