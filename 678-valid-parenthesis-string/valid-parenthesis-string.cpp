class Solution {
public:
    bool checkValidString(string s) {
        int n=s.size();
        int mx=0,mn=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                mn++;
                mx++;
            }
            else if(s[i]==')'){
                mn--;
                mx--;
            }
            else{//s[i]=='*'
                mn--;
                mx++;
            }
            if(mn<0) mn=0;
            if(mx<0) return false;
        }
        return 0>=mn && mx>=0;
    }
};