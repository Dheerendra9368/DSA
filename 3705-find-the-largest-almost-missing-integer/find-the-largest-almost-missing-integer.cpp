class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int idxf=-1;
        int idxl=-1;
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        if(k==1){
            int mx=-1;
            for(auto ele:mp){
                int x=ele.first;
                int freq=ele.second;
                if(freq==1) mx=max(mx,x);
            }
            return mx;
        }
        else if(n==k){
            int mx=-1;
            for(auto ele:mp){
                int x=ele.first;
                mx=max(mx,x);
            }
            return mx;
        }
        bool first=false;
        bool last=false;

        if(mp[nums[0]]==1) first=true;
        if(mp[nums[n-1]]==1) last=true;

        if(first && last) return max(nums[0],nums[n-1]);
        else if(first) return nums[0];
        else if(last) return nums[n-1];
        else return -1;
    }
};