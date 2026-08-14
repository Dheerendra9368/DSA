class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        int i=0,j=0;
        unordered_map<char,int> mp;
        int ans=0;
        while(i<n){
            while(j<n  && mp[s[j]]<=1){
                mp[s[j]]++;
                j++;
            }
            ans=max(ans,j-i);
            if(j<n) while(s[i]!=s[j]){
                mp[s[i]]--;
                i++;
            }
            mp[s[i]]--;
            i++;
        }
        return ans;
    }
};