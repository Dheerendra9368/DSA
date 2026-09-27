class Solution {
public:
    void rev(string &s,int i,int j){
        while(i<j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }
    string reverseParentheses(string s) {
        int n=s.size();
        stack<int> st;//holds the index of '('
        for(int i=0;i<n;i++){
            if(s[i]=='(') st.push(i+1);
            else if(s[i]==')'){
                rev(s,st.top(),i-1);
                st.pop();
            }
        }
        string res="";
        for(char x:s){
           if(x!='(' && x!=')') res+=x;
        }
        return res;
    }
};