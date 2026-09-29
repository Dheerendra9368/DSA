class Solution {
public:
    bool checkall(vector<vector<char>>& grid,int i,int j,int cnt,vector<vector<vector<int>>> &dp){
        int m=grid.size();
        int n=grid[0].size();
        if(i>=m || j>=n) return false;
        if(grid[i][j]=='(') cnt++;
        else{
            if(cnt>0) cnt--;
            else return false;
        }
        if(dp[i][j][cnt]!=-1) return dp[i][j][cnt];
        if((i==m-1) && (j==n-1) && (cnt==0)) return 1;
        bool call1=checkall(grid,i+1,j,cnt,dp);
        bool call2=checkall(grid,i,j+1,cnt,dp);
        return dp[i][j][cnt]=call1 || call2;
    }

    bool valid(string &s){
        int cnt=0;
        for(char x:s){
            if(x=='(') cnt++;
            else{
                if(cnt==0) return false;
                else cnt--;
            }
        }
        return cnt==0;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();        
        if(grid[0][0]==')' || grid[m-1][n-1]=='(') return false;
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(200,-1)));
        return checkall(grid,0,0,0,dp);
    }
};