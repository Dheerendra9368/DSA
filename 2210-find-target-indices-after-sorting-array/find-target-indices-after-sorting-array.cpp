class Solution {
public:
    int left(vector<int>& nums, int target){
        int n=nums.size();
        int lo=0;
        int hi=n-1;
        int ans=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]==target){
                ans=mid;
                hi=mid-1;
            }
            else if(nums[mid]<target) lo=mid+1;
            else hi=mid-1;
        }
        return ans;
    }
    int right(vector<int>& nums, int target){
        int n=nums.size();
        int lo=0;
        int hi=n-1;
        int ans=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]==target){
                ans=mid;
                lo=mid+1;
            }
            else if(nums[mid]<target) lo=mid+1;
            else hi=mid-1;
        }
        return ans;
    }
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int> v;
        int x=left(nums,target);
        int y=right(nums,target);
        if(x!=-1){
            for(int i=x;i<=y;i++){
                v.push_back(i);
            }
        }
        return v;
    }
};