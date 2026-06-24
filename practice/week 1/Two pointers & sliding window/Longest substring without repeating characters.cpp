class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int p1=0;int p2=0;int maxi=1;int n=s.length();
        if(n==0) return 0;
        set<char> chars;
        chars.insert(s[0]);
        while(p1<n-1){
            //cout<<p1<<" "<<p2<<endl;
            p2++;
            if(p2==n) break;
            if(chars.count(s[p2])){
                while(s[p1]!=s[p2]){
                    chars.erase(s[p1]);
                    p1++;
                }
                p1++;
            }else{
                chars.insert(s[p2]);
            }
            maxi=max(maxi,p2-p1+1);
        }
        return maxi;
    }
};