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
    int n,k;cin>>n>>k;
    vi h(n);
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    vi ans(n,0);
    ans[0]=0;
    for(int i=1;i<k;i++){
        ll mini=LLONG_MAX;
        for(int j=0;j<i;j++){
            mini=min(mini,1LL*ans[j]+abs(h[i]-h[j]));
        }
        ans[i]=mini;
    }
    for(int i=k;i<n;i++){
        ll mini=LLONG_MAX;
        for(int j=i-k;j<=i-1;j++){
            mini=min(mini,1LL*ans[j]+abs(h[i]-h[j]));
        }
        ans[i]=mini;
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