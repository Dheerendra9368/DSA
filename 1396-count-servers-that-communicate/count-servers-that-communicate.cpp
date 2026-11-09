class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        int res=0;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<m;j++){
                cnt+=grid[i][j];
            }
            if(cnt>1){
                for(int j=0;j<m;j++){
                    if(grid[i][j]==1) vis[i][j]=true;
                }
                res+=cnt;
            }
        }

        for(int j=0;j<m;j++){
            int cnt=0;
            for(int i=0;i<n;i++){
                cnt+=grid[i][j];
            }
            if(cnt>1){
                for(int i=0;i<n;i++){
                    if(grid[i][j]==1 && !vis[i][j]) res++;
                }
            }
        }

        return res;
    }
};