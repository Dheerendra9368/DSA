class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n=seq.size();
        vector<int> ans(n);
        stack<pair<int,int>> st;
        int t=0;
        for(int i=0;i<n;i++){
            if(seq[i]=='('){
                if(i==0 || st.size()==0){
                    st.push({i,0});
                    ans[i]=0;
                    t=1;
                }
                else{
                    ans[i]=1-st.top().second;
                    st.push({i,1-st.top().second});
                }
            }
            else{
                //seq[i]==')'
                int idx=st.top().first;
                int val=st.top().second;
                st.pop();
                ans[i]=val;
            }
        }
        return ans;
    }
};