class Solution {
public:
    struct state{
        int r;
        int c;
        int e;
        int mask;
    };
    vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    int minMoves(vector<string>& classroom, int energy) {
        int total=0;
        int sr=-1,sc=-1;
        int n=classroom.size();
        int m=classroom[0].size();
        vector<vector<int>> bitMaskPos(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(classroom[i][j]=='L'){
                    bitMaskPos[i][j]=total;
                    total++;
                }
                if(classroom[i][j]=='S'){
                    sr=i;
                    sc=j;
                }
            }
        }
        int all=(1<<total)-1;
        vector<vector<vector<vector<int>>>> vis(n,vector<vector<vector<int>>>(m,
        vector<vector<int>>(energy+1,vector<int>(all+1, 0))));
        queue<state> q;
        q.push({sr,sc,energy,0});
        vis[sr][sc][energy][0]=1;
        int moves=0;
        while(q.size()>0){
            int sz=q.size();
            while(sz--){
                auto ele=q.front();
                int e=ele.e;
                int r=ele.r;
                int c=ele.c;
                int mask=ele.mask;
                q.pop();
                if(mask==all) return moves;
                if(e==0) continue;
                for(int i=0;i<4;i++){
                    int newr=r+dir[i][0];
                    int newc=c+dir[i][1];
                    if(newr<0 || newr>=n || newc<0 || newc>=m || classroom[newr][newc]=='X') continue;
                    int newenergy=e-1;
                    if(classroom[newr][newc]=='R') newenergy=energy;
                    int newmask=mask;
                    if(classroom[newr][newc]=='L') newmask|=(1<<bitMaskPos[newr][newc]);
                    if(vis[newr][newc][newenergy][newmask]==0){
                        vis[newr][newc][newenergy][newmask]=1;
                        q.push({newr,newc,newenergy,newmask});
                    }
                    }
                }
                moves++;
        }

        return -1;
    }
};