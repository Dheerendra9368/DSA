class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int a=0,b=0,c=0;//a=1 && b=2 & c=2
        for(int x:stones){
            int rem=x%3;
            if(rem==1) a++;
            else if(rem==2) b++;
            else c++;
        }
        if(c%2==0) return a>0 && b>0;
        else return abs(a-b)>2;
    }
};