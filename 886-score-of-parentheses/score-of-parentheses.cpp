class Solution {
public:
    int scoreOfParentheses(string s) {
        int n=s.size();
        int curr=0;
        stack<int> st;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(curr);
                curr=0;
            }
            else{//s[i]==')'
                curr=st.top()+max(2*curr,1);
                st.pop();
            }
        }
        
        return curr;
    }
};