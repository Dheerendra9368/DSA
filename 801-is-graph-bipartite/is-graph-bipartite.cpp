class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                queue<int> q;
                q.push(i);
                color[i]=0;
                while(q.size()>0){
                    int x=q.front();
                    int colorx=color[x];
                    q.pop();
                    for(int neighbor:graph[x]){
                        if(color[neighbor]==color[x]) return false;
                        if(color[neighbor]==-1){
                            color[neighbor]=color[x]==0 ? 1:0;
                            q.push(neighbor);
                        }
                    }
                }
            }
        }
        return true;
    }
};