class Solution {
public:
    int dg(int n){
        int cnt=0;
        while(n!=0){
            n/=10;
            cnt++;
        }
        return cnt;
    }
    string intToRoman(int num) {
        vector<string> one={"","I","II","III","IV","V","VI","VII","VIII","IX"};
        vector<string> two={"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        vector<string> three={"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        vector<string> four={"","M","MM","MMM"};

        string ans;
        int digit=dg(num);
        if(digit==1) ans=one[num];
        else if(digit==2) ans=two[num/10]+one[num%10];
        else if(digit==3) ans=three[num/100]+two[(num/10)%10]+one[num%10];
        else ans=four[num/1000]+three[(num/100)%10]+two[(num/10)%10]+one[num%10];
        return ans;
        
    }
};