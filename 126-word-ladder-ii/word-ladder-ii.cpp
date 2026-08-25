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

    vector<vector<string>> ans;
    
    void dfs(string word,string beginWord,unordered_map<string,vector<string>>& parent,vector<string>& path){

        path.push_back(word);
        if(word == beginWord){
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
        } else {
            for(string p : parent[word]){
                dfs(p, beginWord, parent, path);
            }
        }

        path.pop_back();
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,vector<string>> mp;
        unordered_set<string> st(wordList.begin(),wordList.end());
        int n=wordList.size();
        bool beginpre=false;
        bool endpre=false;
        for(int i=0;i<n;i++){
            if(wordList[i]==beginWord) beginpre=true;
            if(wordList[i]==endWord) endpre=true;
            addalldiffbyOne(wordList[i],mp,st);
        }
        if(!endpre) return {};

        if(beginpre==false) addalldiffbyOne(beginWord,mp,st);

        // BFS
        unordered_map<string,int> dist;
        unordered_map<string,vector<string>> parent;

        queue<string> q;

        q.push(beginWord);
        dist[beginWord] = 0;

        while(!q.empty()){

            string s = q.front();
            q.pop();

            for(string neighbor : mp[s]){

                // First time
                if(!dist.count(neighbor)){

                    dist[neighbor] = dist[s] + 1;

                    parent[neighbor].push_back(s);

                    q.push(neighbor);
                }

                // Another shortest parent
                else if(dist[neighbor] == dist[s] + 1){
                    parent[neighbor].push_back(s);
                }
            }
        }

        // No path
        if(!dist.count(endWord))
            return {};

        vector<string> path;

        dfs(endWord, beginWord, parent, path);

        return ans;
    }
};