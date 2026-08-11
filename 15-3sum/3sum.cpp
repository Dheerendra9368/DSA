class Solution {
public:
    vector<vector<int>> helper(int i,int j,vector<int>& nums,int target){
        set<vector<int>> s;
        unordered_map<int,int> mp;
        for(int p=i;p<=j;p++){
            int rem=target-nums[p];
            if(mp.count(rem)){
                s.insert({min(rem,nums[i]),max(rem,nums[i])});
                mp.erase(rem);
            }
            else mp[nums[p]]++;
        }
        vector<vector<int>> ans(s.begin(),s.end());
        return ans;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum<0){
                    j++;
                }
                else if(sum>0){
                    k--;
                }
                else{//sum==0
                    vector<int> temp={nums[i],nums[j],nums[k]};
                    ans.push_back(temp);
                    while(j<n && nums[j]==temp[1]) j++;
                    while(k>=0 && nums[k]==temp[2]) k--;
                }
            }
        }
        return ans;
    }
};