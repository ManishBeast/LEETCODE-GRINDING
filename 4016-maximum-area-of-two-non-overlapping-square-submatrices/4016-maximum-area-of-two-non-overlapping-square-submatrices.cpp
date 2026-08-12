class Solution {
public:
    bool can(vector<vector<int>>& mat,int mid){
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(mat[i-1][j-1]==1){
                    dp[i][j]= min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                }
            }
        }
        vector<vector<int>> pref(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int here = dp[i][j]>=mid;
                    pref[i][j]= max({here,pref[i-1][j],pref[i][j-1]});   
            }
        }
        for(int i=mid;i<=n;i++){
            for(int j=mid;j<=m;j++){
                int r = i-mid;
                int c = j-mid;
                if(dp[i][j]>=mid){
                if((r-mid)>=0 &&pref[r][m]){
                    return true;
                }
                 if((c-mid)>=0 &&pref[n][c]){
                    return true;
                 }
                }
            }
        }
        return false;
    }
    int maxArea(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int left =1;
        int right =min(n,m);
        int ans =0;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(can(mat,mid)){
                ans=mid;
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        return ans*ans;
    }
};