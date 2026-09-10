class Solution {
public:
    long long M=1e9+7;

    long long p(long long a,long long b){//a^b
        long long ans=1;
        while(b>0){
            if(b&1) ans=(ans*a)%M;
            a=(a*a)%M;
            b=b>>1;
        }
        return ans%M;
    }

    int countGoodNumbers(long long n) {
        long long odd=n/2;
        long long even=n-odd;
        long long evenways=5;
        long long oddways=4;
        long long ans=(p(evenways,even)*p(oddways,odd))%M;
        return int(ans);
    }
};