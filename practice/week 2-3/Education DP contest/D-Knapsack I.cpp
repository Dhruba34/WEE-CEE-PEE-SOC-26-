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
    int n,w;cin>>n>>w;
    vi weight(n);vll value(n);
    for(int i=0;i<n;i++){
        cin>>weight[i]>>value[i];
    }
    vll ans(w+1,0);
    for(int i=0;i<n;i++){
        vll tmp=ans;
        for(int j=0;j<=w;j++){
            if(j>=weight[i]){
                if(ans[j]<ans[j-weight[i]]+value[i]){
                    tmp[j]=ans[j-weight[i]]+value[i];
                }
            }
        }
        ans=tmp;
        /**for(int j=0;j<=w;j++){
            cout<<ans[j]<<" ";
        }*/
        //cout<<endl;
    }
    cout<<ans[w]<<endl;
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