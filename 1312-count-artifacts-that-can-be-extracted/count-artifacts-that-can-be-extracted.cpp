class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        vector<vector<int>> mark(n,vector<int>(n,0));
        for(auto ele:dig) mark[ele[0]][ele[1]]=1;
        int cnt=0;
        for(auto ele:artifacts){
            int r1=ele[0];
            int c1=ele[1];
            int r2=ele[2];
            int c2=ele[3];
            bool tflag=true;
            for(int i=r1;i<=r2;i++){
                bool flag=true;
                for(int j=c1;j<=c2;j++){
                    if(!mark[i][j]){
                        flag=false;
                        break;
                    }
                }
                if(!flag){
                    tflag=false;
                    break;
                }
            }
            if(tflag) cnt++;
        }

        return cnt;
    }
};