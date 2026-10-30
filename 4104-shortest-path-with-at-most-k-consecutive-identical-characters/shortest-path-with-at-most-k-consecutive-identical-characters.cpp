class Solution {
public:
    typedef vector<int> v;
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> graph(n);

        for(auto ele:edges){
            int u=ele[0];
            int v=ele[1];
            int wt=ele[2];
            graph[u].push_back({v,wt});
        }
        vector<vector<int>> cost(n,vector<int>(k+1,INT_MAX));//node,consecutive cnt

        priority_queue<v,vector<v>,greater<v>> q;

        cost[0][1]=0;
        q.push({0,1,0});//cost,consecutive cnt,node

        while(q.size()>0){
            int prevcost=q.top()[0];
            int preveq=q.top()[1];
            int u=q.top()[2];
            q.pop();

            if(prevcost!=cost[u][preveq]) continue;

            if(u==n-1) return prevcost;

            for(auto ele:graph[u]){
                int v=ele.first;
                int wt=ele.second;
                int neweq=1;
                if(labels[u]==labels[v]) neweq=preveq+1;
                if(neweq<=k){
                    int newcost=prevcost+wt;

                    if(cost[v][neweq]>newcost){
                        cost[v][neweq]=newcost;
                        q.push({newcost,neweq,v});
                    }
                }
            }
        }

        return -1;                
    }
};