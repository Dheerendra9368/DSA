class Solution {
public:
    static int dgsum(int n){
        int ans=0;
        while(n!=0){
            ans+=(n%10);
            n/=10;
        }
        return ans;
    }
    static bool cmp(int a,int b){
        int da=dgsum(a);
        int db=dgsum(b);
        if(da!=db) return da<db;
        else return a<b;
    }
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp=nums;
        sort(temp.begin(),temp.end(),cmp);
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++) mp[nums[i]]=i;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(temp[i]!=nums[i]){
                int swidx=mp[temp[i]];
                swap(nums[i],nums[swidx]);
                mp[nums[i]]=i;
                mp[nums[swidx]]=swidx;
                cnt++;
            }
        }
        return cnt;
    }
};