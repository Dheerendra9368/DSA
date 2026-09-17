class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> st;
        for(int i=0;i<n-1;i++){
            int s=nums[i]+nums[i+1];
            if(st.count(s)) return true;
            st.insert(s);
        }
        return false;
    }
};