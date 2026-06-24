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
    vector<double> p(n);
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    vector<vector<double>> ans(n+1,vector<double>(n+1,0));
    ans[0][0]=1;
    for(int i=1;i<=n;i++){
        ans[0][i]=ans[0][i-1]*(1-p[i-1]);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i>j) ans[i][j]=0;
            else{
                ans[i][j]=p[j-1]*ans[i-1][j-1]+(1-p[j-1])*ans[i][j-1];
            }
        }
    }
    double sum=0;
    for(int i=n;i>n/2;i--){
        sum+=ans[i][n];
    }
    /**for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }*/
    cout<<fixed<<setprecision(10)<<sum<<endl;
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