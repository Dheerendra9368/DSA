class Solution {
public:
    void f(unordered_map<int,int> &mp,int &ans,int &x){
        if(mp.count(x)){
            for(int i=1;i<=9;i++){
                if(!mp.count(i)) continue;
                for(int j=0;j<=9;j++){
                    if(!mp.count(j)) continue;
                    mp[x]--;
                    mp[i]--;
                    mp[j]--;
                    if(mp[i]>=0 && mp[j]>=0 && mp[x]>=0) ans++;
                    mp[x]++;
                    mp[i]++;
                    mp[j]++;
                }
            }
        }
    }
    int totalNumbers(vector<int>& digits) {
        unordered_map<int,int> mp;
        for(int x:digits) mp[x]++;
        int ans=0;
        for(int i=0;i<9;i+=2) f(mp,ans,i);
        return ans;
    }
};