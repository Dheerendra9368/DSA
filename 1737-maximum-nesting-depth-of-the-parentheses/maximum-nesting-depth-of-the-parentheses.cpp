class Solution {
public:
    int maxDepth(string s) {
        int res=0;
        int cnt=0;
        for(char x:s){
            if(x=='(') cnt++;
            else if(x==')') cnt--;
            res=max(res,cnt);
        }
        return res;
    }
};