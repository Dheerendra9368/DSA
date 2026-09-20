class Solution {
public:
    int secMinedges(vector<vector<int>>& edges,int n){
        vector<vector<int>> graph(n+1);
        for(auto ele:edges){
            int u=ele[0];
            int v=ele[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<vector<int>> vis(n+1,vector<int>(2,-1));//0-shortest 1-second shortest
        vis[1][0]=0;
        queue<pair<int,int>> q;
        q.push({1,0});
        while(q.size()>0){
                int x=q.front().first;
                int dis=q.front().second;
                q.pop();
                for(auto neighbor:graph[x]){
                    if(vis[neighbor][0]==-1){
                        q.push({neighbor,dis+1});
                        vis[neighbor][0]=dis+1;
                    }
                    else if(vis[neighbor][1]==-1 && (dis+1)>vis[neighbor][0]){
                        if(neighbor==n) return dis+1;
                        q.push({neighbor,dis+1});
                        vis[neighbor][1]=dis+1;
                    }
                }
        }
        return -1;
    }
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        int tedges=secMinedges(edges,n);
        cout<<tedges;
        int curr_tm=0;
        for(int i=0;i<tedges;i++){
            //if the curr_tm is in odd phase of change then red signal look chnage =7 1-7 green,7-14 re,15-21 green
            if((curr_tm/change)%2==1){
                //wait until green light means
                curr_tm=((curr_tm/change)+1)*change;
            }
            curr_tm+=time;//for a regular edge
        }
        return curr_tm;
    }
};