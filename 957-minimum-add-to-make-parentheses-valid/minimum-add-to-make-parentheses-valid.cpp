class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') st.push('(');
            else{
                if(st.size()==0) ans++;
                else st.pop();
            }
        }
        ans+=st.size();
        return ans;
    }
};