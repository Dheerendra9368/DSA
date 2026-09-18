class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>> &pos){
        int n=pos.size();
        vector<vector<int>> ans;
        ans.push_back({pos[0][0],pos[0][1]});
        for(int i=1;i<n;i++){
            int st=pos[i][0];
            int end=pos[i][1];
            if(ans[ans.size()-1][1]>st && ans[ans.size()-1][1]<end) ans[ans.size()-1][1]=end;
            else ans.push_back({st,end});
        }
        return ans;
    }

    vector<string> maxNumOfSubstrings(string s) {
        int n=s.size();
        unordered_map<char,pair<int,int>> mp;
        for(int i=0;i<n;i++){
            if(mp.count(s[i])) mp[s[i]].second=i;
            else mp[s[i]]={i,i};
        }
        vector<vector<int>> pos;
        for(auto ele:mp){
            int st=ele.second.first;
            int end=ele.second.second;
            bool valid=true;
            for(int i=st;i<=end;i++){
                if(mp[s[i]].first<st){
                    valid=false;
                    break;
                }
                end=max(end,mp[s[i]].second);
            }
            if(valid) pos.push_back({st,end});
        }
        sort(pos.begin(),pos.end());
        // pos=merge(pos);
        int m=pos.size();
        int cnt=0;
        int len=0;
        vector<vector<int>> ans;
        for(int i=m-1;i>=0;i--){
            int c=1;
            int l=pos[i][1]-pos[i][0]+1;
            vector<vector<int>> temp;
            temp.push_back({pos[i][0],pos[i][1]});
            for(int j=i-1;j>=0;j--){
                if(pos[j][1]<temp[temp.size()-1][0]){
                    c++;
                    l+=(pos[j][1]-pos[j][0]+1);
                    temp.push_back(pos[j]);
                }
                // else{
                //     l+=(pos[j][1]-temp[temp.size()-1][1]+1);
                //     temp[temp.size()-1][1]=pos[j][1];
                // }
            }
            if(c>cnt){
                cnt=c;
                len=l;
                ans=temp;
            }
            else if(c==cnt && l<len){
                len=l;
                ans=temp;
            }
        }
        vector<string> res;
        for(auto ele:ans){
            res.push_back(s.substr(ele[0],ele[1]-ele[0]+1));
        }
        return res;
    }
};