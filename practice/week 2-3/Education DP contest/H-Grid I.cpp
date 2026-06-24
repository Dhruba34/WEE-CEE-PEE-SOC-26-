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
    int h,w;cin>>h>>w;
    vector<string> maze(h+1,"");
    for(int i=0;i<=w;i++){
        maze[0]=maze[0]+"#";
    }
    for(int i=0;i<h;i++){
        string s;
        cin>>s;
        maze[i+1]="#"+s;
    }
    vector<vll> ans(h+1,vll(w+1,0));
    ans[1][1]=1;
    ll mod=1e9+7;
    for(int i=1;i<=h;i++){
        //cout<<"i= "<<i<<endl;
        for(int j=1;j<=w;j++){
            if(maze[i][j]=='#') continue;
            //cout<<"j= "<<j<<endl;
            if(maze[i-1][j]=='.'){
                ans[i][j]=(ans[i][j]+ans[i-1][j])%mod;
            }
            if(maze[i][j-1]=='.'){
                ans[i][j]=(ans[i][j]+ans[i][j-1])%mod;
            }
        }
    }
    /**for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }*/
    cout<<ans[h][w]<<endl;
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