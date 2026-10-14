class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string s="";
        for(int i=1;i<=num;i++){
            int x=-1;
            for(int j=9;j>=0;j--){
                if(sum>=j){
                    x=j;
                    sum-=j;
                    break;
                }
            }
            s+=to_string(x);
        }
        if(sum>0) return "";
        return s;
    }
};