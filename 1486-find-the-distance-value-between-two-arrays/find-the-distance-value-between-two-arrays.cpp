class Solution {
public:
    pair<int,int> neighbour(vector<int>& arr2,int x){
        int lo=0;
        int hi=arr2.size()-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(arr2[mid]<=x) lo=mid+1;
            else hi=mid-1;
        }
        return {hi,lo};
    }

    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n=arr2.size();
        sort(arr2.begin(),arr2.end());
        int cnt=0;
        for(int x:arr1){
            auto ele=neighbour(arr2,x);
            int l=ele.first;
            int r=ele.second;
            if((l==-1 || abs(x-arr2[l])>d) && (r==n || abs(x-arr2[r])>d)) cnt++;
            
        }
        return cnt;
    }
};