class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n,0);
        for(int i=0;i<bookings.size();i++){
            int l = bookings[i][0];
            int r = bookings[i][1];
            int seats = bookings[i][2];

            diff[l-1]+= seats;
             if(r < n)
                diff[r] -= seats;
        }

        for(int i=1;i<n;i++)
            diff[i] += diff[i-1];

        return diff;
    }
};