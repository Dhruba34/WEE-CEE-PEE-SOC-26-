class Solution {
public:
    int maxArea(vector<int>& height) {
        int p1=0;int p2=height.size()-1;
        int maxi=min(height[p1],height[p2])*p2;
        while(p1<p2){
            if(height[p1]<=height[p2]){
                p1++;
            }else{
                p2--;
            }
            maxi=max(maxi,min(height[p1],height[p2])*(p2-p1));
        }
        return maxi;
    }
};