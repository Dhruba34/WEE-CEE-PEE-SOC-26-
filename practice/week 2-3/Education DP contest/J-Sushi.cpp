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
    vi a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    v(v(vd)) ans(n+1,v(vd)(n+1,vd(n+1,0)));
    for(int i=n-1;i>=0;i--){
        for(int j=n-i;j>=0;j--){
            for(int k=n-i-j;k>=0;k--){
                double tmp=(1.0*i*n)/((n-i)*(n-i));
                if(j!=0){
                    ans[i][j][k]+=n*1.0/(n-i)*(j*1.0/n*(ans[i+1][j-1][k]+1))+1.0*j*tmp/n;
                    //cout<<n*1.0/(n-i)*(j*1.0/n*(ans[i+1][j-1][k]+1))<<" "<<1.0*j*tmp/n<<" "<<ans[i][j][k]<<endl;
                }
                if(k!=0){
                    ans[i][j][k]+=n*1.0/(n-i)*(k*1.0/n*(ans[i][j+1][k-1]+1))+1.0*k*tmp/n;
                }
                if(n-i-j-k!=0){
                    ans[i][j][k]+=n*1.0/(n-i)*((n-i-j-k)*1.0/n*(ans[i][j][k+1]+1))+1.0*tmp*(n-i-j-k)/n;
                }
                //cout<<i<<" "<<j<<" "<<k<<" "<<ans[i][j][k]<<endl;
            }
        }
    }
    int o=0;int t=0;
    for(int i=0;i<n;i++){
        if(a[i]==1) o++;
        if(a[i]==2) t++;
    }
    cout<<fixed<<setprecision(10)<<ans[0][o][t]<<endl;
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