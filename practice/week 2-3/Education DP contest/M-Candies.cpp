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
    int n,k;cin>>n>>k;
    vi a(n);
    ll mod=1e9+7;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vll ans(k+1,0);
    for(int i=0;i<=k;i++){
        if(i<=a[0]){
            ans[i]=1;
        }else{
            ans[i]=0;
        }
    }
    /**for(int j=0;j<=k;j++){
        cout<<ans[j]<<" ";
    }
    cout<<endl;*/
    for(int i=1;i<n;i++){
        vll temp=ans;
        ll sum=0;
        for(int j=0;j<=a[i];j++){
            sum=(sum+ans[j])%mod;
            temp[j]=sum;
        }
        for(int j=a[i]+1;j<=k;j++){
            sum=(sum-ans[j-a[i]-1]+ans[j]+mod)%mod;
            temp[j]=sum;
        }
        ans=temp;
        /**for(int j=0;j<=k;j++){
            cout<<ans[j]<<" ";
        }
        cout<<endl;*/
    }
    cout<<ans[k]<<endl;
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