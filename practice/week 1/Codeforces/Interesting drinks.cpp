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
    vi x(n);
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    int q;cin>>q;
    sort(all(x));
    for(int i=0;i<q;i++){
        int a;cin>>a;
        int l=0;int r=n;
        while(l<r){
            int mid=(l+r)/2;
            if(x[mid]>a){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        cout<<l<<endl;
    }
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
}