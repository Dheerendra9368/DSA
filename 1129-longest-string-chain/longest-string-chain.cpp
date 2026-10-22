class Solution {
public:

    bool isPredecessor(string s1,string s2){
        // is s1 a predecessor of s2 we have to check
        int n1=s1.size();
        int n2=s2.size();
        if(n2!=(n1+1)) return false;
        int i=0;
        int j=0;
        while(i<n1 && j<n2){
            if(s1[i]!=s2[j]){
                j++;
            }
            else{
                i++;
                j++;
            }
        }
        return i==n1;
    }

    static bool cmp(string s1,string s2){
        return s1.size()<s2.size();
    }

    void checkAll(unordered_map<string,int> &mp,string &s){
        int n=s.size();
        //every substring of length n-1
        for(int i=0;i<n;i++){
            string temp=s.substr(0,i);
            if(i+1<n) temp+=s.substr(i+1);
            if(mp.count(temp)) mp[s]=max(mp[s],mp[temp]+1);
        }
    }

    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),cmp);
        if(n==1) return 1;
        unordered_map<string,int> mp;
        for(auto ele:words) mp[ele]=1;
        int ans=1;
        for(int i=0;i<n;i++){
            checkAll(mp,words[i]);
            ans=max(ans,mp[words[i]]);
        }
        return ans;
    }
};