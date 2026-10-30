class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> dis(2,vector<int>(n,INT_MAX));

        vector<vector<int>> rgraph(n);
        vector<vector<int>> bgraph(n);
        for(auto ele:redEdges){
            int u=ele[0];
            int v=ele[1];
            rgraph[u].push_back(v);
        }

        for(auto ele:blueEdges){
            int u=ele[0];
            int v=ele[1];
            bgraph[u].push_back(v);
        } 

        dis[0][0]=0;//last used color was red
        dis[1][0]=0;//last used color was blue
        queue<pair<int,int>> q;
        q.push({0,0});//last used color was red
        q.push({0,1});//last used color was blue
        
        while(q.size()>0){
            int sz=q.size();
            while(sz--){
                int u=q.front().first;
                int col=q.front().second;
                q.pop();
                if(col==0){
                    for(auto ele:rgraph[u]){
                        int v=ele;
                        if(dis[1][v]>1+dis[0][u]){
                            dis[1][v]=1+dis[0][u];
                            q.push({v,1});
                        }
                    }
                }
                else{
                    for(auto ele:bgraph[u]){
                        int v=ele;
                        if(dis[0][v]>1+dis[1][u]){
                            dis[0][v]=1+dis[1][u];
                            q.push({v,0});
                        }
                    }                    
                }
            }
        }
        
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i]=min(dis[0][i],dis[1][i]);
            if(ans[i]==INT_MAX) ans[i]=-1;
        }
        return ans;                    
    }
};