class Solution {
public:
    vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};

    void dfs(vector<vector<char>>& board,int r,int c,vector<vector<int>> &vis){
        int n=board.size();
        int m=board[0].size();
        vis[r][c]=1;
        for(int i=0;i<4;i++){
            int newr=r+dir[i][0];
            int newc=c+dir[i][1];
            if(newc<0 || newc>=m || newr<0 || newr>=n || board[newr][newc]=='X') continue;
            if(vis[newr][newc]==0) dfs(board,newr,newc,vis);            
            }
    }

    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));

            for(int j=0;j<m;j++){
                if(board[0][j]=='O' && vis[0][j]==0) dfs(board,0,j,vis);
                if(board[n-1][j]=='O' && vis[n-1][j]==0) dfs(board,n-1,j,vis);
            }
            for(int r=0;r<n;r++){
                if(board[r][0]=='O' && vis[r][0]==0) dfs(board,r,0,vis);
                if(board[r][m-1]=='O' && vis[r][m-1]==0) dfs(board,r,m-1,vis);
            }

            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(board[i][j]=='O' && vis[i][j]==0) board[i][j]='X';
                }
            }

    }
};