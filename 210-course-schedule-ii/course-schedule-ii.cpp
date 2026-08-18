class Solution {
public:
        vector<int> ans;
    bool topoBFS(vector<vector<int>> &graph){
        int n=graph.size();
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++){
            for(int neighbor:graph[i]) indegree[neighbor]++;
        }
        queue<int> q;
        vector<int> vis(n,0);
        int cnt=0;
        
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
                vis[i]=1;
                cnt++;
                ans.push_back(i);
            }
        }
        while(q.size()>0){
            int x=q.front();
            q.pop();
            for(int neighbor:graph[x]){
                if(vis[neighbor]==1) continue;
                indegree[neighbor]--;
                if(indegree[neighbor]==0){
                    vis[neighbor]=1;
                    q.push(neighbor);
                    cnt++;
                    ans.push_back(neighbor);
                }
            }
        }
        return cnt==n;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>> graph(n);
        for(auto ele:prerequisites){
            int a=ele[0];
            int b=ele[1];
            graph[b].push_back(a);
        }
        if(topoBFS(graph)) return ans;
        else return {};
    }
};