class Solution {
public:
    int s(int n){
        int ans=0;
        while(n>0){
            ans+=n%10;
            n/=10;
        }
        return ans;
    }

    int p(int n){
        int ans=1;
        while(n>0){
            ans*=n%10;
            n/=10;
        }
        return ans;
    }

    bool checkDivisibility(int n) {
        int sum=s(n)+p(n);
        return n%sum==0;
    }
};