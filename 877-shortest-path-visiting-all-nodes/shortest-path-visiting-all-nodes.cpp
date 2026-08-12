class Solution {
public:
    typedef pair<int,int> p;
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        if(n==1 || n==0) return 0;
        queue<p> q;//{node,mask}
        set<p> vis;//{node,pathmask}

        for(int i=0;i<n;i++){
            int maskValue=(1<<i);
            q.push({i,maskValue});
            vis.insert({i,maskValue});
        }

        int allvisState=(1<<n)-1;
        int path=0;
        while(q.size()>0){
            int sz=q.size();
            path++;
            while(sz--){
                auto curr=q.front();
                q.pop();
                int currNode=curr.first;
                int currMask=curr.second;
                for(int adj:graph[currNode]){
                    int adjMask=currMask | (1<<adj);
                    if(adjMask==allvisState) return path;
                    if(vis.count({adj,adjMask})) continue;
                    q.push({adj,adjMask});
                    vis.insert({adj,adjMask});
                }
            }
        }
        return -1;
    }
};