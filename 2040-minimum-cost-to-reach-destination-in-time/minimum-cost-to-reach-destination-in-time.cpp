class Solution {
public:
    typedef vector<int> v;
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n=passingFees.size();
        vector<vector<pair<int,int>>> graph(n);

        for(auto ele:edges){
            int u=ele[0];
            int v=ele[1];
            int wt=ele[2];
            graph[u].push_back({v,wt});
            graph[v].push_back({u,wt});
        }

        vector<vector<int>> cost(n,vector<int>(maxTime+1,INT_MAX));

        priority_queue<v,vector<v>,greater<v>> q;

        cost[0][0]=passingFees[0];
        q.push({passingFees[0],0,0});//cost,time,node

        while(q.size()>0){
            int prevcost=q.top()[0];
            int prevtm=q.top()[1];
            int u=q.top()[2];
            q.pop();

            if(prevcost!=cost[u][prevtm]) continue;

            if(u==n-1) return prevcost;

            for(auto ele:graph[u]){
                int v=ele.first;
                int tm=ele.second;

                if(prevtm+tm<=maxTime){
                    int newcost=prevcost+passingFees[v];
                    int newtm=prevtm+tm;

                    if(cost[v][newtm]>newcost){
                        cost[v][newtm]=newcost;
                        q.push({newcost,newtm,v});
                    }
                }
            }
        }

        return -1;
    }
};