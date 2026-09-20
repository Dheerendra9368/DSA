class Solution {
public:
    int reverseDegree(string s) {
        int res=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            int idx=i+1;
            int idxinrevalpha=26-(s[i]-'a');
            res+=(idx*idxinrevalpha);
        }
        return res;
    }
};