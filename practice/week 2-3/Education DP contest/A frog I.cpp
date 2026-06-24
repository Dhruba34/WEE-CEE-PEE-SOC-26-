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
    int n;cin>>n;
    vi h(n);
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    vi ans(n,0);
    ans[0]=0;
    ans[1]=abs(h[1]-h[0]);
    for(int i=2;i<n;i++){
        ans[i]=min(ans[i-1]+abs(h[i]-h[i-1]),ans[i-2]+abs(h[i]-h[i-2]));
    }
    cout<<ans[n-1]<<endl;
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