class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        int n=nums.size();
        unordered_set<int> vis;
        queue<int> q;
        q.push(start);
        vis.insert(start);
        int step=1;
        while(q.size()>0){
            int sz=q.size();
            while(sz--){
            int x=q.front();
            q.pop();
            for(int i=0;i<n;i++){
                int res1=x+nums[i];
                int res2=x-nums[i];
                int res3=x^nums[i];
                if((res1==goal) || (res2==goal) || (res3==goal)) return step;

                if(!(res1>1000 || res1<0 || vis.count(res1))){
                    vis.insert(res1);
                    q.push(res1);
                    }
                if(!(res2>1000 || res2<0 || vis.count(res2))){
                    vis.insert(res2);
                    q.push(res2);
                    }
                if(!(res3>1000 || res3<0 || vis.count(res3))){
                    vis.insert(res3);
                    q.push(res3);
                    }                                
                }                
            }
            step++;
        }
        return -1;
    }
};