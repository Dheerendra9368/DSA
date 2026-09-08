class Solution {
public:

    int maximumSwap(int num) {
        string s=to_string(num);
        int n=s.size();
        vector<int> post(n);
        post[n-1]=n-1;
        for(int i=n-2;i>=0;i--){
            int idx=post[i+1];
            int prev=s[idx]-'0';
            int curr=s[i]-'0';
            if(curr>prev) post[i]=i;
            else post[i]=idx;
        }

        for(int i=0;i<n-1;i++){
            int idx=post[i+1];
            int nextmax=s[idx]-'0';
            int curr=s[i]-'0';
            if(nextmax>curr){
                swap(s[i],s[idx]);
                break;
            }
        }
        num=stoi(s);
        return num;
    }
};