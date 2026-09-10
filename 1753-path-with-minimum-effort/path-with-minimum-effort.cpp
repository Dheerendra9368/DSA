class Solution {
    typedef pair<int,pair<int,int>> pr;
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
        vector<vector<int>> dis(n,vector<int>(m,INT_MAX));
        dis[0][0]=0;
        priority_queue<pr,vector<pr>,greater<pr>> pq;
        pq.push({0,{0,0}});
        while(pq.size()>0){
            int i1=pq.top().second.first;
            int j1=pq.top().second.second;
            int w=pq.top().first;
            pq.pop();
            if(w>dis[i1][j1]) continue;
            for(int i=0;i<4;i++){
                int i2=i1+dir[i][0];
                int j2=j1+dir[i][1];
                if(i2<0 || j2<0 || i2>=n || j2>=m) continue;
                int wt=abs(heights[i1][j1]-heights[i2][j2]);
                if(dis[i2][j2]>max(dis[i1][j1],wt)){
                    dis[i2][j2]=max(dis[i1][j1],wt);
                    pq.push({dis[i2][j2],{i2,j2}});
                }
            }
        }
        return dis[n-1][m-1];
    }
};