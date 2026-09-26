class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count=0;
        int n=nums.size();
        vector<int> pre(n);
        pre[0]=nums[0];
        for(int i=1;i<n;i++) pre[i]=pre[i-1]+nums[i];

        unordered_map<int,int> mp;
        mp[0]++;

        for(int i=0;i<n;i++){
            int rem=(pre[i]%k+k)%k;
            if(mp.count(rem)) count+=mp[rem];
            mp[rem]++;
        }
       return count;
    }        
};