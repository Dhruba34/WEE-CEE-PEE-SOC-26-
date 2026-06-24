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
    int n;ll l,r;cin>>n>>l>>r;
    vll a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(all(a));
    ll sum=0;
    for(int i=0;i<n;i++){
        int p1=0;int p2=0;
        int l1=0;int r1=n;
        while(l1<r1){
            int mid=(l1+r1)/2;
            if(a[mid]>=l-a[i]){
                r1=mid;
            }else{
                l1=mid+1;
            }
        }
        p1=l1;
        l1=-1;r1=n-1;
        while(l1<r1){
            int mid=(l1+r1)/2;
            if(mid*2<l1+r1) mid++;
            if(a[mid]<=r-a[i]){
                l1=mid;
            }else{
                r1=mid-1;
            }
        }
        p2=l1;
        sum+=max(0,p2-p1+1);
        if(p1<=i && i<=p2){
            sum--;
        }
    }
    cout<<sum/2<<endl;
}
int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
}