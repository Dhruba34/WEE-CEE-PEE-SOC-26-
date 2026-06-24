#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int,int>
#define pll pair<long long,long long>
ll powmod(ll a,ll b,ll c){
    ll d=1;
    while(b>1){
        if(b%2==0){
            b=b/2;
        }else{
            b=b/2;
            d=(d*a)%c;
        }
        a=(a*a)%c;
    }
    a=(a*d)%c;
    return a;
}
void solve(){
    string s,t;cin>>s>>t;
    int n=s.length();int m=t.length();
    vector<vi> lastpos(m+1,vi(26,-1));
    for(int i=1;i<=m;i++){
        for(int j=0;j<i;j++){
            lastpos[i][t[j]-'a']=j+1;
        }
    }
    vector<string> actual1(m+1,"");
    vector<string> actual2(m+1,"");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(lastpos[j][s[i-1]-'a']!=-1){
                if(actual1[j].length()>actual1[lastpos[j][s[i-1]-'a']-1].length()+1){
                    actual2[j]=actual1[j];
                }else{
                    actual2[j]=actual1[lastpos[j][s[i-1]-'a']-1]+s[i-1];
                }
            }else{
                actual2[j]=actual1[j];
            }
        }
        actual1=actual2;
    }
    cout<<actual1[m]<<endl;
}
int main() {
    fastio;

    int t=1;
    //cin >> t; // number of test cases (if needed)
    while(t--) {
        solve();
    }

    return 0;
}