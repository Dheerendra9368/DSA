class Solution {
public:
    typedef pair<int,int> p;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<p>> graph(n);
        for(auto ele:flights){
            int u=ele[0];
            int v=ele[1];
            int wt=ele[2];
            graph[u].push_back({wt,v});
        }
        vector<int> dis(n,INT_MAX);
        dis[src]=0;
        queue<p> pq;
        pq.push({0,src});
        int stop=0;
        while(pq.size()>0 && stop<=k){
            int sz=pq.size();
            while(sz--){
                int u=pq.front().second;
            int currdis=pq.front().first;
            pq.pop();
            for(auto ele:graph[u]){
                int wt=ele.first;
                int v=ele.second;
                if(dis[v]>currdis+wt){
                        dis[v]=currdis+wt;
                        pq.push({dis[v],v});                        
                }            
        }
            }
            stop++;
        }
        if(dis[dst]==INT_MAX) return -1;
        else return dis[dst];
    }
};