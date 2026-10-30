class Solution {
public:
    vector<vector<int>> dir={{1,0},{0,1},{0,-1},{-1,0}};

    int shortestPath(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        //at every pos u can reach with diff k value so mark according to that
        vector<vector<vector<int>>> vis(n,vector<vector<int>>(m,vector<int>(k+1,0)));
        queue<vector<int>> q;
        q.push({0,0,k});
        vis[0][0][k]=1;
        int steps=0;

        while(q.size()>0){
            int sz=q.size();
            while(sz--){
                int r=q.front()[0];
                int c=q.front()[1];
                int curr_k=q.front()[2];
                q.pop();
                if(curr_k<0) continue;
                if(r==n-1 && c==m-1) return steps;
                for(int i=0;i<4;i++){
                    int newr=r+dir[i][0];
                    int newc=c+dir[i][1];
                    if(newr<0 || newc<0 || newr>=n || newc>=m) continue;
                    int newk=curr_k-grid[newr][newc];
                    if(newk>=0 && !vis[newr][newc][newk]){
                        q.push({newr,newc,newk});
                        vis[newr][newc][newk]=1;
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};