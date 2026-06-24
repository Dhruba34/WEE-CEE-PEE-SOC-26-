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
    int n;ll t;
    cin>>n>>t;
    vll k(n);
    for(int i=0;i<n;i++){
        cin>>k[i];
    }
    ll l=0;ll r=t*k[0];
    while(l<r){
        ll mid=(l+r)/2;
        //cout<<l<<" "<<mid<<" "<<r<<endl;
        ll sum=0;
        for(int i=0;i<n;i++){
            sum+=mid/k[i];
            if(sum>=t) break;
        }
        //cout<<sum<<endl;
        if(sum>=t){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    cout<<l<<endl;
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
}