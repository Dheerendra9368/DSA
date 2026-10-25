class Solution {
public:
    int stbit(int a){
        int cnt=0;
        while(a!=0){
            a=a&(a-1);
            cnt++;
        }
        return cnt;
    }
    int calculateScore(int a, int b) {
        int s1=stbit(a);
        int s2=stbit(b);
        if(s1>=s2) return s1*s2;
        else return s2/s1;
    }
};