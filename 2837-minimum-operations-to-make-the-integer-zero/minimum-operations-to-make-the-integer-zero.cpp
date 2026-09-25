class Solution {
public:
    int tsetbits(long long n) {
        if(n<=0) return INT_MAX;
        int ans=0;
        while(n>0){
            ans++;
            n=n&(n-1);
        }
        return ans;
    }
    int makeTheIntegerZero(int num1, int num2) {
        if(num1==0) return 0;
        if(num2>=num1) return -1;
        int limit=60;
        int k=1;
       for(int k = 1; k <= 60; k++) {
            long long x = 1LL*num1 -1LL *k *num2;
            if(tsetbits(x)<=k && k<=x) return k;
        }
        return -1;
    }
};