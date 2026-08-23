class Solution {
public:
    bool sumGame(string num) {
        int n=num.size();
        int cntq=0;
        int cntq1=0;
        int sum1=0;
        for(int i=0;i<n/2;i++){
            if(num[i]=='?'){
                cntq++;
                cntq1++;
            }
            else sum1+=num[i]-'0';
        }
        int sum2=0;
        for(int i=n/2;i<n;i++){
            if(num[i]=='?') cntq++;
            else sum2+=num[i]-'0';
        }
        int cntq2=cntq-cntq1;
        if(cntq==0) return sum1!=sum2;
        else if(cntq%2==1) return true;
        else{
            int alicetake=min(cntq/2,cntq1);
            int bobtake=min(cntq/2,cntq2);
            if(sum1+alicetake*9>sum2+bobtake*9) return true;
            alicetake=min(cntq/2,cntq2);
            bobtake=min(cntq/2,cntq1);
            if(sum2+alicetake*9>sum1+bobtake*9) return true;
            else return false;
        }
    }
};