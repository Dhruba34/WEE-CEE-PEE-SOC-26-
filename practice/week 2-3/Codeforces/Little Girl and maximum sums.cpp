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
    vi arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vi temp(n,0);
    for(int i=0;i<q;i++){
        int a,b;cin>>a>>b;
        temp[a-1]++;
        if(b!=n) temp[b]--;
    }
    vll freq(n,0);
    freq[0]=temp[0];
    for(int i=1;i<n;i++){
        freq[i]=freq[i-1]+temp[i];
    }
    vi idx(n,0);
    for(int i=0;i<n;i++){
        idx[i]=i;
    }
    sort(all(idx),[&freq](int a,int b){
        return freq[a]<freq[b];
    });
    sort(all(arr));
    ll sum=0;
    for(int i=0;i<n;i++){
        sum+=freq[idx[i]]*arr[i];
    }
    cout<<sum<<endl;
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
}