


//   Question Link :: "https://practice.geeksforgeeks.org/problems/count-the-reversals0401/1"



// Solutoin //



string filter_string(string str);


int countRev (string s)
{
    if(s.length()%2!=0)
        return -1;
    string filter_str = filter_string(s);
    int changes=0,len=filter_str.length();
    if(len%2!=0)
        return -1;
    // cout<<filter_str.length()<<endl;
    for(int i=0;i<len-1;i+=2)
    {
        if( (filter_str[i] == '}' && filter_str[i+1] == '}') || (filter_str[i] == '{' && filter_str[i+1] == '{') )
            changes+=1;
        else
            changes+=2;
    }
    
    return changes;
}


string filter_string(string str)
{
    string filter_str = "";
    int len = str.length();
    bool signal;
    for(int i=0;i<len;i++)
    {
        if(str[i]=='{')
        {
            int open =1,j=i+1;
            signal=false;
            for(j;j<len;j++)
            {
                if(open<=0)
                    break;
                if(str[j]=='{')
                {
                    open+=1;
                }
                else
                    open-=1;
            }
            
            if(open==0)
            {
                i=j-1;
            }
            else
            {
                filter_str+=str[i];
            }
        }
        else
        {
            filter_str+=str[i];
        }
    
    }
    return filter_str;
}

