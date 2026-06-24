#define vi vector<int>
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vi temp(n);
        int m=bookings.size();
        for(int i=0;i<m;i++){
            temp[bookings[i][0]-1]+=bookings[i][2];
            if(bookings[i][1]!=n) temp[bookings[i][1]]-=bookings[i][2];
        }
        vi ans(n);
        ans[0]=temp[0];
        for(int i=1;i<n;i++){
            ans[i]=ans[i-1]+temp[i];
        }
        return ans;
    }
};