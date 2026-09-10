class Solution {
public:
    typedef pair<int,pair<int,int>> p;
    vector<vector<int>> dir={{1,0},{0,1},{0,-1},{-1,0}};

    int minimumEffortPath(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(n==1 && m==1) return 0;
        vector<vector<int>> dis(n,vector<int>(m,INT_MAX));
        dis[0][0]=0;
        queue<p> q;
        q.push({0,{0,0}});
        while(q.size()>0){
            int r=q.front().second.first;
            int c=q.front().second.second;
            int wt=q.front().first;
            q.pop();
            if(dis[r][c]<wt) continue;
            for(int i=0;i<4;i++){
                int newr=r+dir[i][0];
                int newc=c+dir[i][1];
                if(newr<0 || newc<0 || newr==n || newc==m) continue;
                if(dis[newr][newc]>max(dis[r][c],abs(grid[newr][newc]-grid[r][c]))){
                    dis[newr][newc]=max(dis[r][c],abs(grid[newr][newc]-grid[r][c]));
                    q.push({dis[newr][newc],{newr,newc}});
                }
            }
        }
    
        return dis[n-1][m-1];
    }
};