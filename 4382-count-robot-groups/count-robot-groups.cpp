class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int dis) {
        int n=position.size();
        int ans=0;
        if(n==1) return 1;
        vector<int> sp;
        int i=n-1;
        while(i>=0){
            sp.push_back(speed[i]);
            while(i>0 && (position[i]-position[i-1]<=dis)) i--;
            i--;
        }
        reverse(sp.begin(),sp.end());
        i=sp.size()-1;
        while(i>=0){
            int j=i;
            while(j>0){
                if(sp[i]<sp[j-1]) j--;
                else break;
            }
            i=j-1;
            ans++;
        }
        return ans;
    }
};