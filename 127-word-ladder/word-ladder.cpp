class Solution {
public:
    void addalldiffbyOne(string &s,unordered_map<string,vector<string>> &mp,unordered_set<string> &st){
        int n=s.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<26;j++){
                string p=s;
                p[i]='a'+j;
                if(p!=s && st.count(p)) mp[s].push_back(p);
            }
        }
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,vector<string>> mp;
        unordered_map<string,int> vis;
        unordered_set<string> st;
        for(string x:wordList) st.insert(x);
        int n=wordList.size();
        bool beginpre=false;
        bool endpre=false;
        for(int i=0;i<n;i++){
            if(wordList[i]==beginWord) beginpre=true;
            if(wordList[i]==endWord) endpre=true;
            vis[wordList[i]]=0;
            addalldiffbyOne(wordList[i],mp,st);
        }
        if(!endpre) return 0;

        if(beginpre==false) addalldiffbyOne(beginWord,mp,st);

        queue<string> q;
        q.push(beginWord);
        vis[beginWord]=1;
        int ans=1;
        while(q.size()>0){
            ans++;
            int sz=q.size();
            while(sz--){
                string s=q.front();
                q.pop();
                for(string neighbor:mp[s]){
                    if(vis[neighbor]==1) continue;
                    if(neighbor==endWord) return ans;
                    vis[neighbor]=1;
                    q.push(neighbor);
                }
            }
        }
        return 0;
    }
};