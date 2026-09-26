class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n=s.size();
        unordered_map<string,string> mp;
        for(auto ele:knowledge) mp[ele[0]]=ele[1];
        string ans="";
        int i=0;
        while(i<n){
            if(s[i]!='('){
                ans+=s[i];
                i++;
            }
            else{
                string key="";
                i++;//s[i]=='(' so i++;
                while(s[i]!=')'){
                    key+=s[i];
                    i++;
                }
                //now s[i]==')' so i++
                i++;
                if(mp.count(key)) ans+=mp[key];
                else ans+="?";
            }
        }
        return ans;
    }
};