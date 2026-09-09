class Solution {
public:
    long long countCommas(long long n) {
        long long first=1e6;//less than first has comma 1
        long long second=1e9;//less than second has comma 2(max)
        long long third=1e12;//less than second has comma 3(max)
        long long fourth=1e15;//less than second has comma 4(max)
        // nos from a to b =b-a+1
        if(n<first) return max(n-1000+1,(long long)0);// nos from 1000 to n
        else if(n>=first && n<second) return first-1-1000+1+(n-first+1)*2;//nos from 1000 to first-1 has comma 1 then nos from first to n
        else if(n>=second && n<third) return first-1-1000+1+(second-1-first+1)*2+(n-second+1)*3;
        else if(n>=third && n<fourth) return first-1-1000+1+(second-1-first+1)*2+(third-1-second+1)*3+(n-third+1)*4;
        else return first-1-999+(second-1-first+1)*2+(third-1-second+1)*3+(fourth-1-third+1)*4+(n-fourth+1)*5;
    }
};