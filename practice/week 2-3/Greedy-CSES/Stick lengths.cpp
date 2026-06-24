//olla to cp
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
ll mod=1e9+7;
vll fact(1e5,1);
vll factinv(1e5,1);
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
void factcal(int n,ll m){
    for(int i=2;i<=n;i++){
        fact[i]=(fact[i-1]*i)%m;
    }
}
void factinvcal(int n,ll m){
    for(int i=2;i<=n;i++){
        factinv[i]=powmod(fact[i],m-2,m);
    }
}
ll gcd(ll a,ll b){
    while(b%a){
        ll c=b%a;
        b=a;
        a=c;
    }
    return a;
}
ll lcm(ll a,ll b){
    return (a*b)/gcd(a,b);
}
 
void dfs(vector<vi>& adj,int cur,int p,v(vll)& dp){
    for(int i:adj[cur]){
        if(i==p) continue;
        dfs(adj,i,cur,dp);
        dp[cur][0]=(dp[cur][0]*(dp[i][0]+dp[i][1])%mod)%mod;
        dp[cur][1]=(dp[cur][1]*dp[i][0])%mod;
    }
}
//bye to cp
 
 
void solve(){
    int n;cin>>n;
    vll p(n);
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    sort(all(p));
    ll med=0;
    ll med2=0;
    if(n%2==0){
        med=p[(n-1)/2];
        med2=p[(n-1)/2+1];
    }else{
        med=p[(n-1)/2];
    }
    ll cost=0;
    ll cost2=0;
    for(int i=0;i<n;i++){
        cost+=abs(med-p[i]);
        cost2+=abs(med2-p[i]);
    }
    cout<<min(cost,cost2)<<endl;
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