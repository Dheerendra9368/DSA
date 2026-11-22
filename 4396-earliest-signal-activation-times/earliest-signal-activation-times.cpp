class Solution {
public:
    typedef pair<long long,int> p;
    vector<long long> earliestActivationTimes(int n, vector<vector<int>>& edges, vector<int>& requiredSignals) {
        vector<long long> ans(n,LLONG_MAX);
        vector<long long> cnt(n,0);
        vector<vector<p>> graph(n);
        for(auto ele:edges){
            int u=ele[0];
            int v=ele[1];
            int wt=ele[2];
            graph[u].push_back({wt,v});
        }
        priority_queue<p,vector<p>,greater<p>> q;
        ans[0]=0;
        requiredSignals[0]=1;
        q.push({0,0});
        while(q.size()>0){
            auto ele=q.top();
            q.pop();
            int u=ele.second;
            long long wt=ele.first;
            if(ans[u]<wt) continue;
            cnt[u]++;
            if(cnt[u]==requiredSignals[u]) ans[u]=wt;
            if(cnt[u]==requiredSignals[u]){
                for(auto ele:graph[u]){
                int v=ele.second;
                long long w=ele.first;
                if(ans[v]>w+wt){
                    q.push({w+wt,v});
                }
            }
            }
            
        }
        for(int i=0;i<n;i++){
            if(ans[i]==LLONG_MAX) ans[i]=-1;
        }
        return ans;
    }
};