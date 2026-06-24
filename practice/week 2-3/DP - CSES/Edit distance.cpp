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
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.length();
    int m=s2.length();
    v(vi) dist(n+1,vi(m+1,6000));
    for(int i=0;i<=m;i++){
        dist[0][i]=i;
    }
    for(int i=1;i<=n;i++){
        dist[i][0]=i;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int a=dist[i-1][j];
            int b=dist[i][j-1];
            int c=dist[i-1][j-1];
            int cost=0;
            if(s1[i-1]!=s2[j-1]) cost++;
            dist[i][j]=min(a+1,min(b+1,c+cost));
        }
    }
    /**for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }*/
    /**
    cout<<endl;
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            cout<<mini[i][j]<<" ";
        }
        cout<<endl;
    }*/
    cout<<dist[n][m]<<endl;
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