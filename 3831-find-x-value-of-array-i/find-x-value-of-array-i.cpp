class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long> ans(k,0);
        vector<long long> prev(k,0);
        
        for(int i=0;i<n;i++){
            
            vector<long long> currCount(k,0);

            int currElerem=nums[i]%k;
            currCount[currElerem]++;

            for(int oldrem=0;oldrem<k;oldrem++){
                int newrem=((long long)oldrem*nums[i]%k)%k;
                currCount[newrem]+=prev[oldrem];
            }

            prev=move(currCount);

            for(int rem=0;rem<k;rem++){
                ans[rem]+=prev[rem];
            }
        }
        return ans;
    }
};