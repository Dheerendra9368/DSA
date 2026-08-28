class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx=-1;
        int n=nums.size();
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                idx=i;
                break;
            }
        }
        if(idx==-1){
            int i=0,j=n-1;
            while(i<j) swap(nums[i++],nums[j--]);
            return;
        }
        int i=idx+1,j=n-1;
        while(i<j) swap(nums[i++],nums[j--]);
        int idx2=-1;
        i=idx+1;
        while(i<n){
            if(nums[i]>nums[idx]){
                idx2=i;
                break;
            }
            i++;
        }
        swap(nums[idx],nums[idx2]);
        
    }
};