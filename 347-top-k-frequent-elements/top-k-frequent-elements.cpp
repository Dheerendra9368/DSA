class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> mp;
    for(int i=0;i<nums.size();i++) mp[nums[i]]++;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(auto ele:mp){
        int x=ele.first;
        int frq=ele.second;
        pq.push({frq,x});
        if(pq.size()>k){
            pq.pop();
        }
    }
    vector<int> ans;
    while(pq.size()>0){
        int x=(pq.top()).second;
        ans.push_back(x);
        pq.pop();
    }
    return ans;
}
};