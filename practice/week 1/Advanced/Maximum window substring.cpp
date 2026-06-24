class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int> freq;
        set<char> imp;
        int n=s.length();
        for(char c:t){
            freq[c]++;
            imp.insert(c);
        }
        vector<int> v(imp.begin(),imp.end());
        int p1=-1;int p2=-1;int dist=0;map<char,int> freq2;
        for(int i=0;i<n;i++){
            if(imp.count(s[i])){
                p1=i;break;
            }
        }
        if(p1==-1) return "";
        p2=p1-1;
        for(int i=0;i<v.size();i++){
            //cout<<v[i]<<endl;
            while(freq2[v[i]]<freq[v[i]]){
                //cout<<p2<<" "<<freq2[v[i]]<<" "<<freq[v[i]]<<endl;
                if(p2==n-1){
                    return "";
                }
                p2++;
                if(imp.count(s[p2])){
                    freq2[s[p2]]++;
                }
            }
        }
        int ans=p2-p1+1;
        int p1final=p1;int p2final=p2;
        //cout<<p1<<" "<<p2<<endl;
        while(true){
            while(true){
                if(imp.count(s[p1])>0 && freq2[s[p1]]==freq[s[p1]]){
                    break;
                }else{
                    p1++;
                    if(imp.count(s[p1-1])) freq2[s[p1-1]]--;
                    if(ans>p2-p1+1){
                        ans=p2-p1+1;
                        p1final=p1;p2final=p2;
                    }
                }
            }
            if(p2>=n-1) break;
            p2++;
            //cout<<p2<<endl;
            if(imp.count(s[p2])) freq2[s[p2]]++;
            //cout<<p1<<" "<<p2<<endl;
            while(s[p1]!=s[p2]){
                p2++;
                if(p2<n && imp.count(s[p2])) freq2[s[p2]]++;
                if(p2>n-1) break;
            }
        }
        return s.substr(p1final,ans);
    }
};