class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> res(m);
        for(int i=0;i<m;i++){
            string str="";
            for(int j=0;j<n;j++){
                if(j==n-1 || i==0) str+=".";
                else str+="#";
            }
            res[i]=str;
        }
        return res;
    }
};