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
    vi a(n);vi b(n);vi c(n);
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    vi enda(n);
    vi endb(n);
    vi endc(n);
    enda[0]=a[0];
    endb[0]=b[0];
    endc[0]=c[0];
    for(int i=1;i<n;i++){
        enda[i]=max(endb[i-1]+a[i],endc[i-1]+a[i]);
        endb[i]=b[i]+max(enda[i-1],endc[i-1]);
        endc[i]=c[i]+max(enda[i-1],endb[i-1]);
    }
    cout<<max(enda[n-1],max(endb[n-1],endc[n-1]))<<endl;
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