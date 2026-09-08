class Solution {
public:
    int cnt(int n){
        int ans=0;
        while(n>0){
            n/=10;
            ans++;
        }
        return ans;
    }
    int countCommas(int n) {
        int c=cnt(n);
        if(c<4) return 0;
        else return n-999;
    }
};