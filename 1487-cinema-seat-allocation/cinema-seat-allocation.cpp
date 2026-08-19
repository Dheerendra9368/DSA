class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,vector<int>> mp;
        int ans=0;
        for(auto ele:reservedSeats){
            int row=ele[0];
            int seat=ele[1];
            if(seat==1 || seat==10) continue;
            mp[row].push_back(seat);
        }

        ans+=(n-mp.size())*2;

        for(auto ele:mp){
            int row=ele.first;
            int grpA=1;
            int grpB=1;
            int grpC=1;
            for(int seat:mp[row]){
                if(seat==2 || seat==3 || seat==4 || seat==5) grpA=-1;
                if(seat==4 || seat==5 || seat==6 || seat==7) grpB=-1;
                if(seat==6 || seat==7 || seat==8 || seat==9) grpC=-1;
            }
            if(grpA==-1 && grpB==-1 && grpC==-1) continue;
            else ans++;
        }
        return ans;
    }
};