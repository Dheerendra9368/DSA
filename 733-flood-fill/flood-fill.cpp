class Solution {
public:
    vector<vector<int>> dir={{1,0},{0,1},{0,-1},{-1,0}};
    void f(vector<vector<int>>& image, int sr, int sc, int &color,vector<vector<int>> &vis,int &orgcolor){
        int n=image.size();
        int m=image[0].size();
        vis[sr][sc]=1;
        image[sr][sc]=color;
        for(int i=0;i<4;i++){
            int newr=sr+dir[i][0];
            int newc=sc+dir[i][1];
            if(newr<0 || newr>=n || newc<0 || newc>=m || vis[newr][newc]==1 || image[newr][newc]!=orgcolor) continue;
            f(image,newr,newc,color,vis,orgcolor);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        if(image[sr][sc]==color) return image;
        vector<vector<int>> vis(n,vector<int>(m,0));
        int orgcolor=image[sr][sc];
        f(image,sr,sc,color,vis,orgcolor);
        return image;
    }
};