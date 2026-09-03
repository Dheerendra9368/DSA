class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        if(nums1.size()==1) return true;
        int oddc=0,evenc=0;
        int mnodd=INT_MAX,mneven=INT_MAX;
        for(int x:nums1){
            if(x%2==0){
                evenc++;
                mneven=min(mneven,x);
            }
            else{
                oddc++;
                mnodd=min(mnodd,x);
            }
        }
        if(oddc==0 || evenc==0) return true;
        else return mnodd<mneven;
        // else
    }
};