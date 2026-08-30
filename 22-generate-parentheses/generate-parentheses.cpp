class Solution {
public:
void parenth(string s,int op,int cl,int n,vector<string> & v){
    if(op==n && cl==n){
       v.push_back(s);
        return;
    }
    if(op!=n) parenth(s+'(',op+1,cl,n,v);
    if(cl<op) parenth(s+')',op,cl+1,n,v);
}
    vector<string> generateParenthesis(int n) {
        vector<string>  v;
        string s;
        parenth(s,0,0,n,v);
        return v;
    }
};