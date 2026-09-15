class Solution {
public:
    bool isPalindrome(string &s,int l,int r){
        if(l<0) return false;
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    int maxPalindromes(string s, int k) {
        int n=s.size();
        int cnt=0;
        int lst=-1;//last index where palindromic substring end
        //we will check for every index if the substring of length k or k+1 ends here
        for(int i=0;i<n;i++){
            //of length k
            if(i-k+1>lst && isPalindrome(s,i-k+1,i)){
                cnt++;
                lst=i;
            }
            //of length k+1
            else if(i-k>lst && isPalindrome(s,i-k,i)){
                cnt++;
                lst=i;
            }
        }
        return cnt;
    }
};