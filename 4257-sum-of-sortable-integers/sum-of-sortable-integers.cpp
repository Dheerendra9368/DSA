class Solution {
public:
    void rev(vector<int> &nums,int i,int j){
        while(i<j) swap(nums[i++],nums[j--]);
    }

    void rotate(vector<int> &nums,int i,int j){
        int dropIdx = -1;
        for (int k=i;k<j;k++) {
            if (nums[k]>nums[k+1]) {
                dropIdx=k;
                break;
            }
        }
        if(dropIdx==-1) return;//already sorted
        int k= j-(dropIdx+1)+1;
        rev(nums,i,j);
        rev(nums,i,i+k-1);
        rev(nums,i+k,j);        
    }

    bool isSorted(vector<int> &nums){
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i]) return false;
        }
        return true;
    }

        bool canSort(vector<int> &nums,int i,int j){
        int cnt=0;
        for(int k=i;k<=j;k++){
            if(k+1<=j && nums[k]>nums[k+1]) cnt++;
            if(cnt>1) return false;
        }
        if(cnt==0 || (cnt==1 && nums[i]>=nums[j])){
            return true;
        }
        return false;
    }

    int sortableIntegers(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 1;
        int ans=0;
        if(isSorted(nums)) ans++;
        for(int k=2;k<=n/2;k++){
            if(n%k==0){
                vector<int> temp=nums;
                bool flag=true;
                for(int i=0;i<n;i+=k){
                    flag=canSort(temp,i,i+k-1);
                    if(!flag) break;
                    rotate(temp,i,i+k-1);
                }
                if(flag && isSorted(temp)) ans+=k;
            }
        }
        if(canSort(nums,0,n-1)) ans+=n;
        return ans;
    }
};