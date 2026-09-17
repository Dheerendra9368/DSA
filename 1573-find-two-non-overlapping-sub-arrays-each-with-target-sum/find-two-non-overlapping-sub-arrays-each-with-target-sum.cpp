class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        int res=INT_MAX;
        vector<int> mnlentillidx(n,INT_MAX);
        int i=0;
        int j=0;
        int currsum=0;
        int mnlen=INT_MAX;
        while(j<n){
            currsum+=arr[j];
            while(i<j && currsum>target){
                currsum-=arr[i];
                i++;
            }
            if(currsum==target){
                int len=j-i+1;
                if(i>0 && mnlentillidx[i-1]!=INT_MAX){
                    res=min(res,len+mnlentillidx[i-1]);
                }
                mnlen=min(mnlen,len);
            }
            mnlentillidx[j]=mnlen;
            j++;
        }
        return res==INT_MAX ? -1:res;
    }
};