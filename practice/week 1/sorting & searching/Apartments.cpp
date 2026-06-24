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
    int n,m;cin>>n>>m;
    ll k;cin>>k;
    vll a(n);vll b(m);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    sort(all(a));
    sort(all(b));
    int ans=0;
    int mini=0;
    for(int i=0;i<n;i++){
        int pos=findpos(b,a[i]-k,mini,m);
        //cout<<i<<" "<<pos<<" "<<a[i]<<endl;
        if(pos==m){
            //cout<<"line 45"<<endl;
            break;
        }
        if(b[pos]>a[i]+k){
            //cout<<"line 49"<<endl;
            continue;
        }
        mini=pos+1;
        //cout<<mini<<endl;
        ans++;
        if(mini==m) break;
    }
    cout<<ans<<endl;
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
}