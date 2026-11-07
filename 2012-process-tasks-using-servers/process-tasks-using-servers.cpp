class Solution {
public:
    typedef pair<int,int> p;
    typedef pair<long long,int> q;
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n=servers.size();
        int m=tasks.size();
        priority_queue<p,vector<p>,greater<p>> frees;//{weight,idx}
        for(int i=0;i<n;i++) frees.push({servers[i],i});
        priority_queue<q,vector<q>,greater<q>> busys;//{when_it_will_be_free,idx}
        long long tm=0;
        vector<int> ans(m);
        for(int i=0;i<m;i++){
            tm=max(tm,(long long)i);
            //clean the busy server
            if(frees.size()==0){
                tm=max(tm,busys.top().first);
            }
            while(busys.size()>0 && busys.top().first<=tm){
                int idx=busys.top().second;
                busys.pop();
                frees.push({servers[idx],idx});
            }
            auto ele=frees.top();
            frees.pop();
            int idx=ele.second;
            ans[i]=idx;
            busys.push({tm+tasks[i],idx});
        }
        return ans;
    }
};