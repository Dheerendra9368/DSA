class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dis(n,vector<int>(n,INT_MAX));

        for(auto ele:edges){
            int u=ele[0];
            int v=ele[1];
            int wt=ele[2];
            dis[u][v]=wt;
            dis[v][u]=wt;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dis[i][k]!=INT_MAX && dis[k][j]!=INT_MAX){
                        dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                        dis[j][i]=dis[i][j];
                    }
                }
            }
        }                
        int ans=INT_MAX;
        int idx=-1;
        for(int i=n-1;i>=0;i--){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(i!=j && dis[i][j]<=distanceThreshold) cnt++;
            }
            if(cnt<ans){
                ans=cnt;
                idx=i;
            }
        }
        return idx;
    }
};