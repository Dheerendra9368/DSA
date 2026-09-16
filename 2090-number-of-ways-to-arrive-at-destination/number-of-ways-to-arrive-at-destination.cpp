class Solution {
public:
const int MOD=1e9+7;
  typedef pair<long long,int> p;

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> graph(n);
        
        for(auto ele:roads){
            int u=ele[0];
            int v=ele[1];
            int wt=ele[2];
            graph[u].push_back({wt,v});
            graph[v].push_back({wt,u});
        }
        vector<long long> dis(n,LLONG_MAX);
        vector<int> tways(n,0);
        dis[0]=0;
        tways[0]=1;
        priority_queue<p,vector<p>,greater<p>> pq;
        pq.push({0,0});
        while(pq.size()>0){
            int u=pq.top().second;
            int currdis=pq.top().first;
            pq.pop();
            if(currdis>dis[u]) continue;
            for(auto ele:graph[u]){
                int wt=ele.first;
                int v=ele.second;
                //first time arriving
                if(dis[v]>dis[u]+wt){
                    tways[v]=tways[u];
                    dis[v]=dis[u]+wt;
                    pq.push({dis[v],v});
                }
                else if(dis[v]==dis[u]+wt) tways[v]=(tways[v]%MOD+tways[u]%MOD)%MOD;   
        }
        }
        return tways[n-1];           
    }
};