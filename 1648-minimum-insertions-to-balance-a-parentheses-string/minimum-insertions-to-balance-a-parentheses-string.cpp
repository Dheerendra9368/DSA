class Solution {
public:
    int minInsertions(string s) {
        int cnt=0;
        stack<char> st;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='(') st.push('(');
            else{
                // x==')' they must exist in doublet iiiiggggg
                if(i+1<n && s[i+1]==')'){
                    i++;
                    if(!st.empty()) st.pop();
                    else cnt++;
                }
                else{//either next is nothing or '('
                    if(!st.empty()){
                        st.pop();
                        cnt++;//for next ')'
                    }
                    else cnt+=2;
                }
            }
        }
        cnt+=2*st.size();
        return cnt;
    }
};