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
    int n,c;cin>>n>>c;
    vll x(n);
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    sort(all(x));
    ll l=0;ll r=LLONG_MAX;
    while(l<r){
        ll mid=(l+r)/2;
        //cout<<l<<" "<<mid<<" "<<r<<endl;
        if(mid*2<l+r){
            mid++;
        }
        ll prev=x[0];
        int count=1;
        for(int i=1;i<n;i++){
            if(prev+mid<=x[i]){
                count++;
                prev=x[i];
            }
        }
        //cout<<count<<endl;
        if(count>=c){
            l=mid;
        }else{
            r=mid-1;
        }
    }
    cout<<l<<endl;
}
int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
}