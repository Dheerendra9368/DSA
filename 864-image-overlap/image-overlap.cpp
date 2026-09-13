class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<vector<int>> img1cor;
        vector<vector<int>> img2cor;
        int n=img1.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(img1[i][j]==1) img1cor.push_back({i,j});
                if(img2[i][j]==1) img2cor.push_back({i,j});
            }
        }
        map<pair<int,int>, int> mp;
        int ans=0;
        for(auto ele:img1cor){
            int x1=ele[0];
            int y1=ele[1];
            for(auto ele2:img2cor){
                int x2=ele2[0];
                int y2=ele2[1];
                int dx=x2-x1;
                int dy=y2-y1;
                mp[{dx,dy}]++;
                ans=max(ans,mp[{dx,dy}]);
            }
        }
        return ans;
    }
};