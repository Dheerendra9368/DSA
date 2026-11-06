class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b){
        return a[1]<b[1];
    }
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m=logs.size();
        int k=queries.size();
        sort(logs.begin(),logs.end(),cmp);
        unordered_map<int,int> mp;
        int l=0,r=0;
        vector<vector<int>> temp(k);
        for(int i=0;i<k;i++) temp[i]={i,queries[i]};
        sort(temp.begin(),temp.end(),cmp);
        vector<int> arr(k);
        for(int i=0;i<k;i++){
            int stt=temp[i][1]-x;;
            int endt=temp[i][1];
            while(l<m && stt>logs[l][1]){
                int s=logs[l][0];
                if(mp.count(s)){
                    mp[s]--;
                    if(mp[s]==0) mp.erase(s);
                }
                l++;
            }
            if(l>r) r=l;
            while(r<m && logs[r][1]<=endt){
                mp[logs[r][0]]++;
                r++;
            }
            int zrs=n-mp.size();
            arr[temp[i][0]]=zrs;
        }
        return arr;
    }
};