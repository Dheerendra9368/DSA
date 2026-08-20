class Solution {
public:

    string find(unordered_map<string,string> &parent,string a){
        if(parent[a]==a) return a;
        return parent[a]=find(parent,parent[a]);
    }

    void Union(unordered_map<string,string> &parent,string a,string b){
        a=find(parent,a);
        b=find(parent,b);

        if(a!=b)
            parent[b]=a;
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        unordered_map<string,string> parent;
        unordered_map<string,string> owner;

        // initialize
        for(auto &acc:accounts){

            string name=acc[0];

            for(int i=1;i<acc.size();i++){

                string email=acc[i];

                if(parent.find(email)==parent.end())
                    parent[email]=email;

                owner[email]=name;

                Union(parent,acc[1],email);
            }
        }

        unordered_map<string,vector<string>> groups;

        // group emails by root
        for(auto &p:parent){

            string email=p.first;

            string root=find(parent,email);

            groups[root].push_back(email);
        }

        vector<vector<string>> ans;

        for(auto &g:groups){

            vector<string> curr;

            string root=g.first;

            curr.push_back(owner[root]);

            vector<string> emails=g.second;

            sort(emails.begin(),emails.end());

            for(auto &e:emails)
                curr.push_back(e);

            ans.push_back(curr);
        }

        return ans;
    }
};