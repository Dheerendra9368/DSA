class Solution {
public:
    pair<bool,long long> topfreq(unordered_map<int,int> &mp,int k){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    bool flag=(mp.size()>=k);
    for(auto ele:mp){
        int x=ele.first;
        int frq=ele.second;
        pq.push({frq,x});
        if(pq.size()>k){
            pq.pop();
        }
    }

    long long sum=0;
    while(pq.size()>0){
        int x=(pq.top()).second;
        sum+=1LL*x*(pq.top()).first;
        pq.pop();
    }
    return {flag,sum};      
    }
    

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n=nums.size();
        unordered_map<int,int> mp;
        vector<int> ans(n-k+1);
        int i=0;
        long long curr_sum=0;
        while(i<k){
            curr_sum+=1LL*nums[i];
            mp[nums[i]]++;
            i++;
        }

        for(int j=0;j<n-k+1;j++){
            auto ele=topfreq(mp,x);
            if(ele.first==true) ans[j]=ele.second;
            else ans[j]=curr_sum;
            curr_sum-=nums[i-k];
            mp[nums[i-k]]--;
            if(mp[nums[i-k]]==0) mp.erase(nums[i-k]);
            if(i<n) curr_sum+=nums[i];
            if(i<n) mp[nums[i]]++;
            i++;
        }
        return ans;   
    }
};