class Solution {
public:
    vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        int fresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1) fresh++;
            }
        }
        int ans=0;
        while(q.size()>0 && fresh>0){
            int sz=q.size();
            while(sz--){
                auto ele=q.front();
                q.pop();
                int r=ele.first;
                int c=ele.second;
                for(int i=0;i<4;i++){
                    int newr=r+dir[i][0];
                    int newc=c+dir[i][1];
                    if(newr<0 || newr>=n || newc<0 || newc>=m) continue;
                    if(grid[newr][newc]==1){
                        q.push({newr,newc});
                        grid[newr][newc]=2;
                        fresh--;
                    }
                }
            }
            ans++;
        }
        if(fresh>0) return -1;
        else return ans;
    }
};