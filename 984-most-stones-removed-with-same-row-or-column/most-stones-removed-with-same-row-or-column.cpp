
class Solution {
public:

    int find(vector<int> &parent,int x){
    //this method return which group/cluster x belong to
    //T.C.=O(log*n)
    if(parent[x]==x) return x;
    return parent[x]=find(parent,parent[x]);
}

void Union(vector<int> &parent,vector<int> &rank,int a,int b){
    a=find(parent,a);
    b=find(parent,b);

    if(rank[a]>=rank[b]){
        parent[b]=a;
        rank[a]++;
    }
    else{
        parent[a]=b;
        rank[b]++;
    }
}
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int maxRow=0;
        int maxCol=0;
        for(auto it:stones){
            maxRow=max(maxRow,it[0]);
            maxCol=max(maxCol,it[1]);
        }
        vector<int> parent(maxCol+maxRow+2);
        vector<int> rank(maxCol+maxRow+2,1);

        for(int i=0;i<parent.size();i++) parent[i]=i;

        for(auto it:stones){
            int nodeRow=it[0];
            int nodeCol=it[1]+maxRow+1;
            Union(parent,rank,nodeRow,nodeCol);
        }
        int cnt=0;
        for(int i=0;i<parent.size();i++){
            if(parent[i]==i && rank[i]>1) cnt++;
        }
        return n-cnt;
    }
};