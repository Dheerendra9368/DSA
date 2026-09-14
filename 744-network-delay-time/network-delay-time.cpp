class Solution {
public:
    typedef pair<int,int> p;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<p>> graph(n+1);
        for(auto ele:times){
            int u=ele[0];
            int v=ele[1];
            int wt=ele[2];
            graph[u].push_back({wt,v});
        }
        vector<int> dis(n+1,INT_MAX);
        dis[k]=0;
        priority_queue<p,vector<p>,greater<p>> pq;
        pq.push({0,k});
        while(pq.size()>0){
            int u=pq.top().second;
            int currdis=pq.top().first;
            pq.pop();
            if(currdis>dis[u]) continue;
            for(auto ele:graph[u]){
                int wt=ele.first;
                int v=ele.second;
                if(dis[v]>dis[u]+wt){
                    dis[v]=dis[u]+wt;
                    pq.push({dis[v],v});
                }            
        }
        }
        int ans=0;
        for(int i=1;i<=n;i++) ans=max(ans,dis[i]);
        if(ans==INT_MAX) return -1;
        else return ans;
    }
};