#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define vll vector<long long>
#define vd vector<double>
#define pii pair<int,int>
#define pll pair<long long,long long>
#define v(x) vector<x>
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
void dfs(vector<vi>& adj,vi& dist,int node){
    int length=0;
    for(int i:adj[node-1]){
        if(dist[i]!=-1){
            length=max(length,dist[i]+1);
            continue;
        }
        dfs(adj,dist,i+1);
        length=max(dist[i]+1,length);
    }
    dist[node-1]=length;

}
void solve(){
    int n;cin>>n;
    vll a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    v(vll) ans(n+1,vll(n,0));
    vll sums(n+1,0);
    for(int i=1;i<=n;i++){
        sums[i]=sums[i-1]+a[i-1];
    }
    for(int i=2;i<=n;i++){
        for(int j=0;j<=n-i;j++){
            ll mini=LLONG_MAX;
            for(int k=1;k<=i-1;k++){
                mini=min(mini,ans[i-k][j+k]+ans[k][j]+sums[j+i]-sums[j]);
            }
            ans[i][j]=mini;
        }
    }
    /**for(int i=1;i<=n;i++){
        for(int j=0;j<=n-i;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }*/

    cout<<ans[n][0]<<endl;
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