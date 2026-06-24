class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        int ans=0;
        vector<map<double,int>> slope(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(points[i][0]!=points[j][0]){
                    slope[i][(points[i][1]-points[j][1])*1.0/(points[i][0]-points[j][0])]++;
                }else{
                    slope[i][100000]++;
                }
            }
            /**for(auto p:slope[i]){
                cout<<p.first<<" "<<p.second<<endl;
            }*/
            //cout<<endl;
            int maxi=slope[i][0];
            for(auto p:slope[i]){
                if(p.second>maxi){
                    maxi=p.second;
                }
            }
            ans=max(ans,maxi+1);
        }
        return ans;

    }
};