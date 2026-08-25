class Solution {
public:
    bool diffbyone(string a,string b){
        int n=a.size();
        bool flag=true;
        for(int i=0;i<n;i++){
            if(a[i]!=b[i]){
                if(!flag) return false;
                flag=false;
            }
        }
        return true;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,vector<string>> mp;
        unordered_map<string,int> vis;
        int n=wordList.size();
        bool beginpre=false;
        bool endpre=false;
        for(int i=0;i<n;i++){
            if(wordList[i]==beginWord) beginpre=true;
            if(wordList[i]==endWord) endpre=true;
            vis[wordList[i]]=0;
            for(int j=i+1;j<n;j++){
                if(diffbyone(wordList[i],wordList[j])){
                    mp[wordList[i]].push_back(wordList[j]);
                    mp[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        if(!endpre) return 0;
        if(beginpre==false){
            for(int i=0;i<n;i++){
                if(diffbyone(wordList[i],beginWord)){
                    mp[beginWord].push_back(wordList[i]);
                    mp[wordList[i]].push_back(beginWord);
                }
            }
        }
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