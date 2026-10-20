class Solution {
public:

    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0) continue;
                else if(i>0 && j>0){
                    int a=matrix[i-1][j];
                    int b=matrix[i-1][j-1];
                    int c=matrix[i][j-1];
                    matrix[i][j]+=min(a,min(b,c));
                }
                ans+=matrix[i][j];
            }
        }
        return ans;        
    }
};