class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
        vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
        int dis=0;
        while(q.size()>0){
            int sz=q.size();
            dis++;
            while(sz--){
                auto ele=q.front();
                q.pop();
                int r=ele.first;
                int c=ele.second;
                for(int i=0;i<4;i++){
                    int newr=r+dir[i][0];
                    int newc=c+dir[i][1];
                    if(newc<0 || newc>=m || newr<0 || newr>=n) continue;
                    if(mat[newr][newc]!=0 && vis[newr][newc]==0){
                        mat[newr][newc]=dis;
                        vis[newr][newc]=1;
                        q.push({newr,newc});
                    }
                }
            }
        }
        return mat;
    }
};