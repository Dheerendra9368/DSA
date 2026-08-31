class Solution {
public:
    int find(int x,vector<int> &par){
        if(par[x]==x) return x;
        return par[x]=find(par[x],par);
    }

    void Union(int a,int b,vector<int>& par,vector<int> &sz){
        a=find(a,par);
        b=find(b,par);
        if(a==b) return;
        if(sz[a]>=sz[b]){
            par[b]=a;
            sz[a]+=sz[b];
        }
        else{
            par[a]=b;
            sz[b]+=sz[a];
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> par(n);
        vector<int> sz(n,1);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
        for(auto ele:edges){
            Union(ele[0],ele[1],par,sz);
        }
        long long ans=0;
        long long sum=0;
        int remaining=n;
        for(int i=0;i<n;i++){
            if(par[i]==i){
                remaining-=sz[i];
                ans+=1LL*sz[i]*remaining;
            }
        }
        
        return ans;
    }
};