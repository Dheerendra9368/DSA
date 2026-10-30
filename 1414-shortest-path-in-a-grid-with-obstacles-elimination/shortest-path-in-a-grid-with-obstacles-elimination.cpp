class Solution {
public:
    vector<vector<int>> dir={{1,0},{0,1},{0,-1},{-1,0}};

    int mn(int r,int c,vector<vector<int>>& grid, int k,vector<vector<vector<int>>> &dp,vector<vector<int>> &vis){
        int n=grid.size();
        int m=grid[0].size();        
        if(k<0) return INT_MAX;
        if(r==n-1 && c==m-1) return 0;
        if(dp[r][c][k]!=-1) return dp[r][c][k];
        vis[r][c]=1;
        int ans=INT_MAX;
        for(int i=0;i<4;i++){
            int newr=r+dir[i][0];
            int newc=c+dir[i][1];
            if(newr<0 || newc<0 || newr>=n || newc>=m || vis[newr][newc]) continue;
            int temp;
            if(grid[newr][newc]==1) temp=mn(newr,newc,grid,k-1,dp,vis);
            else temp=mn(newr,newc,grid,k,dp,vis);
            if(temp!=INT_MAX) ans=min(ans,1+temp);
        }
        vis[r][c]=0;
        return dp[r][c][k]=ans;
    }
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        if(k>=n+m-2) return n+m-2;
        // vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(k+1,-1)));
        // vector<vector<int>> vis(n,vector<int>(m,0));
        // int ans=mn(0,0,grid,k,dp,vis);
        // if(ans!=INT_MAX) return ans;
        // else return -1;

        queue<vector<int>> q;
        if(grid[0][0]==0) q.push({0,0,k});
        else q.push({0,0,k-1});

        vector<vector<int>> kval(n,vector<int>(m,-1));//max obstacle destroyer available for (i,j)
        if(grid[0][0]==0) kval[0][0]=k;
        else kval[0][0]=k-1;
        int steps=0;
        while(q.size()>0){
            int sz=q.size();
            while(sz--){
                int r=q.front()[0];
                int c=q.front()[1];
                int obs=q.front()[2];
                if(r==n-1 && c==m-1) return steps;
                q.pop();
                if(obs<0) continue;
                for(int i=0;i<4;i++){
                    int newr=r+dir[i][0];
                    int newc=c+dir[i][1];
                    if(newr<0 || newc<0 || newr>=n || newc>=m) continue;
                    int newobs=obs-grid[newr][newc];

                    // Only explore if we have enough k left AND
                    // we reached (newr, newc) with strictly more k than prior visits
                    if(newobs>=0 && newobs>kval[newr][newc]){
                        kval[newr][newc]=newobs;
                        q.push({newr,newc,newobs});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};