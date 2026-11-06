class Solution {
public:
    bool parseBoolExpr(string expression) {
        int n=expression.size();
        stack<char> st;
        char temp=' ';
        char op=' ';
        for(int i=0;i<n;i++){
            char ch=expression[i];
            if(ch=='!' || ch=='&' || ch=='|' || ch=='t' || ch=='f') st.push(ch);
            else if(ch==')'){
                bool hasT=false;
                bool hasF=false;
                while(!st.empty() && st.top()!='|' && st.top()!='&' && st.top()!='!'){
                    if(st.top()=='t') hasT=true;
                    if(st.top()=='f') hasF=true;
                    st.pop();
                }
                if(!st.empty()){
                    op=st.top();
                    st.pop();
                }
                if(op=='|'){
                   temp=hasT ? 't' : 'f';
                }
                else if(op=='&'){
                    temp=hasF ? 'f' : 't';
                }
                else if(op=='!'){
                    temp=hasT? 'f' :'t';
                }
                st.push(temp);             
            }
        }
        return st.top()=='t';
    }
};