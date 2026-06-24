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
    int n,q;cin>>n>>q;
    vll x(n);
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    vll sums(n);
    sums[0]=x[0];
    for(int i=1;i<n;i++){
        sums[i]=sums[i-1]+x[i];
    }
    for(int i=0;i<q;i++){
        int a,b;cin>>a>>b;
        cout<<sums[b-1]-sums[a-1]+x[a-1]<<endl;
    }
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
}