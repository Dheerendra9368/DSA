class Solution {
public:
int find(vector<int>& par,int x){
        if(par[x]==x) return x;
        return par[x]=find(par,par[x]);
    }
    
    void Union(int a,int b,vector<int>& par,vector<int> & rank){
        a=find(par,a);
        b=find(par,b);
        if(rank[a]>=rank[b]){
            par[b]=a;
            rank[a]++;
        }
        else{
            par[a]=b;
            rank[b]++;
        }
    }
    
    static bool cmp(vector<int> &a,vector<int> & b){
        return a[2]<b[2];
    }
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        int n=V;
        vector<int> par(n);
        vector<int> rank(n,1);
        for(int i=0;i<n;i++) par[i]=i;
        sort(edges.begin(),edges.end(),cmp);
        int edgecnt=0;
        int ans=0;
        int i=0;
        while(edgecnt<n-1){
            int a=edges[i][0];
            int b=edges[i][1];
            int srcPar=find(par,a);
            int destPar=find(par,b);
            if(srcPar!=destPar){
                Union(srcPar,destPar,par,rank);
                edgecnt++;
                ans+=edges[i][2];
            }
            i++;
        }
        return ans;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<int>> edges;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                edges.push_back({i,j,abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1])});
            }
        }
        return kruskalsMST(n,edges);
    }
};