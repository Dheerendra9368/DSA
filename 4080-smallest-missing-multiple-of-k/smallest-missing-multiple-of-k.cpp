class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st;
        for(int x:nums) st.insert(x);
        int i=1;
        while(1){
            if(!st.count(i*k)) return i*k;
            i++;
        }
        return 0;
    }
};