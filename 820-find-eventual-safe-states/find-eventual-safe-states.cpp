class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
        //just we have to apply topo sort for outdegrre==reverse of indegree
        int n=g.size();
        vector<int> indegree(n,0);
        vector<vector<int>> graph(n);
        for(int i=0;i<n;i++){
            for(int neighbor:g[i]){
                graph[neighbor].push_back(i);
                indegree[i]++;
            }
        }
        vector<int> ans;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
                ans.push_back(i);
            }
        }
        while(q.size()>0){
            int x=q.front();
            q.pop();
            for(int neighbor:graph[x]){
                indegree[neighbor]--;
                if(indegree[neighbor]==0){
                    q.push(neighbor);
                    ans.push_back(neighbor);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};