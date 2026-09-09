class Solution {
public:
    typedef pair<int,pair<int,int>> p;

    vector<vector<int>> dir={{1,0},{0,1},{1,1},{0,-1},{-1,0},{1,-1},{-1,1},{-1,-1}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1) return -1;
        int n=grid.size();
        vector<vector<int>> dis(n,vector<int>(n,INT_MAX));
        dis[0][0]=1;
        priority_queue<p,vector<p>,greater<p>> pq;
        pq.push({1,{0,0}});
        while(pq.size()>0){
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            int wt=pq.top().first;
            pq.pop();
            if(dis[r][c]<wt) continue;
            for(int i=0;i<8;i++){
                int newr=r+dir[i][0];
                int newc=c+dir[i][1];
                if(newr<0 || newc<0 || newr==n || newc==n || grid[newr][newc]==1) continue;
                if(dis[newr][newc]>dis[r][c]+1){
                    dis[newr][newc]=dis[r][c]+1;
                    pq.push({dis[newr][newc],{newr,newc}});
                }
            }
        }
        if(dis[n-1][n-1]==INT_MAX) return -1;
        else return dis[n-1][n-1];
    }
};