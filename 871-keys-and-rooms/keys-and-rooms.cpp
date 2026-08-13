class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool> vis(n);
                queue<int> q;
                q.push(0);
                vis[0]=true;
                while(q.size()>0){
                    int x=q.front();
                    q.pop();
                    for(int neighbor:rooms[x]){
                        if(vis[neighbor]==true) continue;
                        vis[neighbor]=true;
                        q.push(neighbor);
                }
                }
        for(bool x:vis){
            if(x==false) return false;
        }
        return true;
    }
};