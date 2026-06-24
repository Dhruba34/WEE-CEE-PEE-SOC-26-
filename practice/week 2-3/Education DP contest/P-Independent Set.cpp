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
ll mod=1e9+7;
void dfs(vector<vi>& adj,int cur,int p,v(vll)& dp){
    for(int i:adj[cur]){
        if(i==p) continue;
        dfs(adj,i,cur,dp);
        dp[cur][0]=(dp[cur][0]*(dp[i][0]+dp[i][1])%mod)%mod;
        dp[cur][1]=(dp[cur][1]*dp[i][0])%mod;
    }
}
void solve(){
    int n;cin>>n;
    vi a(n);
    v(vi) adj(n);
    for(int i=0;i<n-1;i++){
        int x,y;cin>>x>>y;
        adj[x-1].pb(y-1);
        adj[y-1].pb(x-1);
    }
    v(vll) dp(n,vll(2,1));
    dfs(adj,0,-1,dp);
    /**cout<<endl;
    for(int i=0;i<n;i++){
        cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
    }*/
    cout<<(dp[0][0]+dp[0][1])%mod<<endl;
    
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