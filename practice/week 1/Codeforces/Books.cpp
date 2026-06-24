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
    int n;cin>>n;
    ll t;cin>>t;
    vi a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int p1=0;int p2=-1;
    ll sum=0;int maxi=0;
    while(p2<n-1){
        p2++;
        sum+=a[p2];
        if(sum>t){
            sum-=a[p1];
            p1++;
        }
        maxi=max(maxi,p2-p1+1);
    }
    cout<<maxi<<endl;
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
}