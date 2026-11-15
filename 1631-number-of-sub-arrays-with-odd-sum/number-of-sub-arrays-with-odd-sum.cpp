class Solution {
public:
    int MOD=1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        long long ans=0;
        int n=arr.size();
        vector<int> preodd(n,0);
        vector<int> preeven(n,0);
        if(arr[0]%2==0) preeven[0]=1;
        else preodd[0]=1;
        ans+=preodd[0];
        for(int i=1;i<n;i++){
            if(arr[i]%2==0){
                preeven[i]++;
                preeven[i]+=preeven[i-1];
                preodd[i]+=preodd[i-1];
            }
            else{
                preodd[i]++;
                preodd[i]+=preeven[i-1];
                preeven[i]+=preodd[i-1];
            }
            
            ans+=preodd[i];
            ans=ans%MOD;
        }
        return ans;
    }
};