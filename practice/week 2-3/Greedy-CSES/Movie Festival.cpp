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
int findpos(vll& b,ll ele,int bound,int m){
    int l=bound;
    int r=m;
    while(l<r){
        int mid=(l+r)/2;
        if(b[mid]<ele){
            l=mid+1;
        }else{
            r=mid;
        }
    }
    return r;
}
void solve(){
    int n,x;cin>>n>>x;
    vi p(n);int xpos=0;
    for(int i=0;i<n;i++){
        cin>>p[i];
        if(p[i]==x){
            xpos=i;
        }
    }
    if(n==1){
        cout<<0<<endl;
        return;
    }
    int l=0;int r=n;
    vector<vi> ans;
    if(p[(l+r)/2]==x){
        while(r-l!=1){
            int mid=(l+r)/2;
            if(p[mid]<=x){
                l=mid;
            }else{
                r=mid;
            }
        }
        if(p[l]==x){
            cout<<0<<endl;
            return;
        }else{
            ans.push_back({xpos+1,l+1});
        }
    }else{
        int cur=xpos;
        if(p[(l+r)/2]<x && xpos>(l+r)/2){
            ans.push_back({1,xpos+1});
            int c=p[0];
            p[0]=p[xpos];
            p[xpos]=c;
            cur=0;
        }else if(p[(l+r)/2]>x && xpos<(l+r)/2){
            ans.push_back({n,xpos+1});
            int c=p[n-1];
            p[n-1]=p[xpos];
            p[xpos]=c;
            cur=n-1;
        }
        while(r-l!=1){
            int mid=(l+r)/2;
            if(p[mid]<=x){
                l=mid;
            }else{
                r=mid;//olla to cp
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
    v(vll) time(n,vll(2));
    for(int i=0;i<n;i++){
        cin>>time[i][0]>>time[i][1];
    }
    sort(all(time),[](vll& a,vll& b){
        return a[1]<b[1];
    });
    ll start=0;
    int c=0;
    for(int i=0;i<n;i++){
        if(time[i][0]>=start){
            c++;
            start=time[i][1];
        }
    }
    cout<<c<<endl;
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
            }
        }
        ans.push_back({cur+1,l+1});
    }
    cout<<ans.size()<<endl;
    for(auto v:ans){
        cout<<v[0]<<" "<<v[1]<<endl;
    }
}
int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
}