class Solution {
public:
    bool checkString(string s) {
        bool flag=true;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(!flag && s[i]=='a') return false;
            else if(s[i]=='b') flag=false;
        }
        return true;
    }
};