class Solution {
public:
vector<int> mdays={0,31,28,31,30,31,30,31,31,30,31,30,31};//ith month has mdays[i] days in it

    string mx(string a,string b){
        int x=stoi(a);
        int y=stoi(b);
        if(x>y) return a;
        else return b;
    }

    string mn(string a,string b){
        int x=stoi(a);
        int y=stoi(b);
        if(x>y) return b;
        else return a;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        arriveAlice=arriveAlice.substr(0,2)+arriveAlice.substr(3);
        leaveAlice=leaveAlice.substr(0,2)+leaveAlice.substr(3);
        arriveBob=arriveBob.substr(0,2)+arriveBob.substr(3);
        leaveBob=leaveBob.substr(0,2)+leaveBob.substr(3);

        string acarrive=mx(arriveAlice,arriveBob);
        string acleave=mn(leaveAlice,leaveBob);

        if(acleave==acarrive) return 1;
        else if(mx(acleave,acarrive)==acarrive) return 0;
        else{
            int arrivemonth=(acarrive[0]-'0')*10+(acarrive[1]-'0');
            int arriveday=(acarrive[2]-'0')*10+(acarrive[3]-'0');
            int leavemonth=(acleave[0]-'0')*10+(acleave[1]-'0');
            int leaveday=(acleave[2]-'0')*10+(acleave[3]-'0');
            if(arrivemonth==leavemonth) return leaveday-arriveday+1;
            else{
                int ans=0;
                for(int i=arrivemonth;i<=leavemonth;i++){
                    int x;
                    if(i==arrivemonth) x=mdays[i]-arriveday+1;
                    else if(i==leavemonth) x=leaveday;
                    else x=mdays[i];
                    ans+=x;
                }
                return ans;
            }
        }

    }
};