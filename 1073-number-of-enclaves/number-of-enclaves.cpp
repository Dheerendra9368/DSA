class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int total1=0;
        int count=0;
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    total1++;
                    if(i==0 || i==n-1 || j==0 || j==m-1){
                        q.push({i,j});
                        vis[i][j]=1;
                        count++;
                    }
                }
            }
        }
        vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
        while(q.size()>0){
            auto it=q.front();
            q.pop();
            int row=it.first;
            int col=it.second;
            for(int i=0;i<4;i++){
                int newrow=row+dir[i][0];
                int newcol=col+dir[i][1];
                if(newrow<0 || newcol<0 || newrow>=n || newcol>=m) continue;
                if(grid[newrow][newcol]==1){
                    if(vis[newrow][newcol]==0){
                        count++;
                        vis[newrow][newcol]=1;
                        q.push({newrow,newcol});
                    }
                }
            }
        }
        return total1-count;

    }
};