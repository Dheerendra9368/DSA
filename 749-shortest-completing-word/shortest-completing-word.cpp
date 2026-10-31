class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> f(26,0);
        for(char x:licensePlate){
            if(x==' ' || (x>='0' && x<='9')) continue;
            else if(x>='a' && x<='z') f[x-'a']++;
            else f[x-'A']++;
        }
        string ans="";
        int len=INT_MAX;
        for(auto ele:words){
            vector<int> freq(26,0);
            for(char x:ele) freq[x-'a']++;
            bool flag=true;
            for(int i=0;i<26;i++){
                if(f[i]>freq[i]) flag=false;
            }
            if(flag && len>ele.size()){
                len=ele.size();
                ans=ele;
            }
        }
        return ans;
    }
};