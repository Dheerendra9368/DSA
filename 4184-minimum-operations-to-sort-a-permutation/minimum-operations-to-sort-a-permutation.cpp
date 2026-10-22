class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        if(n==1 || (n==2 && nums[0]<nums[1])) return 0;
        else if(n==2) return 1;
        int conf=0;
        int cnt=0;
        int pos=-1;
        for(int i=0;i<n;i++){
            int next=(i+1)==n ? 0:(i+1);
            if(nums[next]<nums[i]) conf++;
            if(nums[i]==i) cnt++;
            if(nums[i]==n-1) pos=i;
        }
        pos++;
        if(conf==1 || conf==n-1){
            if(cnt==n) return 0;
            else if(nums[0]==n-1 && nums[n-1]==0) return 1;
            else if(nums[0]==0 || nums[n-1]==n-1) return 2;
            else return min(pos,1+n-pos+1);
        }
        else return -1;
        
    }
};