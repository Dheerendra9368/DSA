class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,pair<int,vector<int>>> mp;
        //first occurance ->nothing
        //second occurance ->dis
        //third occurcance just check
        for(int i=0;i<n;i++){
            if(!mp.count(nums[i])){
                mp[nums[i]].first=1;
                mp[nums[i]].second.push_back(i);
            }
            else if(mp[nums[i]].first==1){
                mp[nums[i]].first=2;
                mp[nums[i]].second.push_back(i);
            }
            else if(mp[nums[i]].first==2){
                int firstocc=mp[nums[i]].second[0];
                int secocc=mp[nums[i]].second[1];
                if(secocc-firstocc==i-secocc) mp[nums[i]]={3,{}};
                else mp[nums[i]]={4,{}};
            }
            else mp[nums[i]]={4,{}};
        }
        int ans=0;
        for(auto ele:mp){
            if(ele.second.first==3) ans++;
        }
        return ans;
    }
};