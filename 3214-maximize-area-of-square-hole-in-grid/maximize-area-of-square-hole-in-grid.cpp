class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int szh=hBars.size();
        if(hBars[szh-1]==n+2) szh--;
        int szv=vBars.size();
        if(vBars[szv-1]==m+2) szv--;
        int i=0;
        if(hBars[0]==1) i++;
        int mxhz=0;
        while(i<szh){
            int j=i+1;
            int cnt=1;
            while(j<szh && hBars[j]==hBars[i]+1){
                cnt++;
                i++;
                j++;
            }
            mxhz=max(mxhz,cnt);
            i++;
        }
        i=0;
        if(vBars[0]==1) i++;
        int mxvr=0;
        while(i<szv){
            int j=i+1;
            int cnt=1;
            while(j<szv && vBars[j]==vBars[i]+1){
                cnt++;
                i++;
                j++;
            }
            mxvr=max(mxvr,cnt);
            i++;
        }
        int ans=min(mxhz+1,mxvr+1);
        return ans*ans;     
    }
};