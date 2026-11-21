class Solution {
public:
    int f(vector<vector<int>> &child,int i,vector<int> &ans){
        for(int c:child[i]){
            ans[i]+=f(child,c,ans);
        }
        return ans[i];
    }

    void st(vector<vector<int>> &child,vector<int> &parent,vector<int> arr,int i,string &s){
        char ch=s[i]-'a';
        if(arr[ch]!=-1) parent[i]=arr[ch];
        arr[ch]=i;
        for(int c:child[i]){
            st(child,parent,arr,c,s);
        }
    }
    vector<int> findSubtreeSizes(vector<int> &parent, string s) {
        int n=parent.size();
        vector<vector<int>> child(n);
        vector<int> arr(26,-1);
        for(int i=1;i<n;i++){
            child[parent[i]].push_back(i);
        }
        st(child,parent,arr,0,s);
        vector<vector<int>> newchild(n);
        for(int i=1;i<n;i++){
            newchild[parent[i]].push_back(i);
        }        
        vector<int> ans(n,1);
        f(newchild,0,ans);
        return ans;
    }
};