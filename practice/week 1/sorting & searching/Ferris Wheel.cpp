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
    int n;ll x;cin>>n>>x;
    vll p(n);
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    sort(all(p));
    int ans=0;
    int i=0;
    int j=n-1;
    while(i<=j){
        if(i==j){
            ans++;
            break;
        }
        if(p[i]+p[j]<=x){
            ans++;
            j--;i++;
        }else{
            ans++;
            j--;
        }
    }
    cout<<ans<<endl;
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
}