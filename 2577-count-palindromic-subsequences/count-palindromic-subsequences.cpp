class Solution {
public:
    int MOD=1e9+7;
    typedef long long ll;
    int Rev(int x){
        if(x<10) return x*10;
        else return 10*(x%10)+x/10;
    }

    int countPalindromes(string s) {
        int n=s.size();
        vector<ll> forcnt(10,0);//all are digits max 10 digits
        vector<ll> bckcnt(10,0);
        vector<ll> forsub(100,0);//combo of 2 max 100 can be there
        vector<ll> bcksub(100,0);

        for(int i=n-1;i>=0;i--){
            int x=s[i]-'0';
            for(int j=0;j<10;j++){
                if(bckcnt[j]>0) bcksub[10*x+j]+=bckcnt[j];
            }
            bckcnt[x]++;
        }

        ll ans=0;
        //three steps 1)remove backwardcnt and subsequence
        //             2)ans+=
        //             3)add forward cnt and subsequence

        for(int i=0;i<n;i++){
            int x=s[i]-'0';
            //step 1
            bckcnt[x]--;
            for(int j=0;j<10;j++){
                if(bckcnt[j]>0) bcksub[10*x+j]-=bckcnt[j];
            }

            //step 2;
            for(int j=0;j<100;j++){
                int r=Rev(j);
                ans+=forsub[j]*bcksub[r];
                ans%=MOD;
            }

            //step 3

            for(int j=0;j<10;j++){
                if(forcnt[j]>0) forsub[10*j+x]+=forcnt[j];
            }
            forcnt[x]++;
        }

        return ans;
    }
};