class Solution {
public:
    void merges(int n,vector<int>& nums,int& ans){
        if(n==1){
            return;
        }
        vector<int> a;vector<int> b;
        for(int i=0;i<n/2;i++){
            a.push_back(nums[i]);
        }
        for(int i=n/2;i<n;i++){
            b.push_back(nums[i]);
        }
        merges(n/2,a,ans);
        merges(n-n/2,b,ans);
        for(int i=0;i<n-n/2;i++){
            int p=upper_bound(a.begin(),a.end(),2LL*b[i])-a.begin();
            ans+=n/2-p;
        }
        int p1=0;int p2=0;
        vector<int> temp;
        while(p1<n/2 || p2<n-n/2){
            if(p1==n/2){
                temp.push_back(b[p2]);
                p2++;
            }else if(p2==n-n/2){
                temp.push_back(a[p1]);
                p1++;
            }else{
                if(a[p1]<b[p2]){
                    temp.push_back(a[p1]);
                    p1++;
                }else{
                    temp.push_back(b[p2]);
                    p2++;
                }
            }
        }
        nums=temp;
    }
    int reversePairs(vector<int>& nums) {
        int ans=0;int n=nums.size();
        merges(n,nums,ans);
        return ans;
    }
};