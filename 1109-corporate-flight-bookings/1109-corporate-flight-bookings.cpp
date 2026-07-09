class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n,0);
        for(int i=0;i<bookings.size();i++){
            int l = bookings[i][0];
            int r = bookings[i][1];
            for(int j=l;j<=r;j++){
                ans[j-1]+=bookings[i][2]; // as given 1 bases index but we storing 0 based na so substract 1 bro 
            }
        }
        return ans;
    }
};