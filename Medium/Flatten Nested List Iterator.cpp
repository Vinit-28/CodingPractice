

// Question Link :: "https://leetcode.com/problems/flatten-nested-list-iterator/"


// Solution //

class NestedIterator {
public:
    stack<NestedInteger> st;
    NestedIterator(vector<NestedInteger> &nestedList) {
        fillStack(nestedList);
    }
    
    void fillStack(vector<NestedInteger> &nestedList){
        
        for(int i=nestedList.size()-1; i>=0; i--){
            if( nestedList[i].isInteger() )
                st.push(nestedList[i]);
            else
                fillStack(nestedList[i].getList());
        }
    }
    
    int next() {
        auto ele = st.top().getInteger();
        st.pop();
        return ele;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};
