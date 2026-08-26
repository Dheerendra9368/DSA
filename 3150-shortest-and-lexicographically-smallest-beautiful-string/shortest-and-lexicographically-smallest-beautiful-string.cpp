class Solution {
public:

    string shortestBeautifulSubstring(string s, int k) {
        vector<string> arr;
        int ans=INT_MAX;
        int n=s.size();
        int i=0;
        while(i<n && s[i]!='1') i++;
        if(i==n) return "";
        while(i<n){
            int j=i;
            int cnt=0;
            while(cnt<k && j<n){
                if(s[j]=='1') cnt++;
                j++;
            }
            if(cnt<k && j==n) break;
            // ans=min(ans,j-i);
            if(ans>=j-i){
                ans=j-i;
                string temp="";
                for(int k=i;k<j;k++) temp+=s[k];
                arr.push_back(temp);
            }
            i++;
            while(i<n && s[i]!='1') i++;    
            }
            cout<<ans;
            // if(arr.size()==0) return "";
            string t="";
            for(string x:arr){
                if(x.size()==ans){
                    if(t=="") t=x;
                    else t=min(t,x);
                }
            }
            return t;
    }
};