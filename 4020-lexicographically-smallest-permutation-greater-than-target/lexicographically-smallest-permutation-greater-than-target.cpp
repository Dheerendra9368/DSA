class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n=s.size();
        vector<int> mp(26,0);
       for(int i=0;i<n;i++){
            mp[s[i]-'a']++;
       }
       string ans="";
       for(int i=0;i<n;i++){
            char x=target[i];
            if(mp[x-'a']>0){
                ans+=x;
                mp[x-'a']--;
            }
            else{
            bool flag=false;
            for(char c=x+1;c<='z';c++){
                if(mp[c-'a']>0){
                    ans+=c;
                    mp[c-'a']--;
                    flag=true;
                    break;
                }
            }
            if(!flag){
             for (int j=i-1;j>=0;j--) {
                    char prev = ans[j];
                    mp[prev - 'a']++;
                    ans.pop_back();
                    for (char c =target[j]+1;c<='z';c++) {
                        if (mp[c-'a']>0) {
                            ans+=c;
                            mp[c-'a']--;

                            for (int k = 0; k < 26; k++) {
                                while (mp[k] > 0) {
                                    ans += ('a' + k);
                                    mp[k]--;
                                }
                            }
                            return ans;
                        }
                    }
                }
                return "";
            }  
            else{
                for(char c='a';c<='z';c++){
                    int freq=mp[c-'a'];
                    for(int k=1;k<=freq;k++) ans+=c;
                }
                return ans;
            }
            }
       }

       if(ans==target){
        for (int i =n -1;i>=0;i--) {
            char prev=ans[i];
            mp[prev-'a']++;
            ans.pop_back();
            for (char c =target[i]+1;c<='z';c++) {
                if (mp[c-'a']>0) {
                    ans+= c;
                    mp[c-'a']--;

                    for (int k=0;k<26;k++) {
                        while (mp[k]>0) {
                            ans+=('a'+k);
                            mp[k]--;
                        }
                    }
                    return ans;
                }
            }
        }
    }
       return "";
    }
};