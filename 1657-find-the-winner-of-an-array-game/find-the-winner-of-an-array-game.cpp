class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n=arr.size();
        if(k>=n-1){
            int mx=arr[0];
            for(int x:arr) mx=max(x,mx);
            return mx;
        }
        else{
            int i=0;
            while(i<n){
                int st=i;
                int cnt=0;
                if(i>0 && arr[i-1]<arr[i]) cnt++;
                st++;
                if(st==n) st=0;
                while(cnt<k){
                    if(arr[i]>arr[st]) cnt++;
                    else break;
                    st++;
                    if(st==n) st=0;
                }
                if(cnt==k) return arr[i];
                i=st;
            }
        }
        return 0;
    }
};