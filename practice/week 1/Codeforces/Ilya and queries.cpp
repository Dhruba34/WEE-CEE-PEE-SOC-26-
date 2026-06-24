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
    int n,m;string s;
    cin>>s;
    cin>>m;
    n=s.length();
    vi temp(n);
    temp[0]=0;
    for(int i=1;i<n;i++){
        if(s[i]==s[i-1]){
            temp[i]=temp[i-1]+1;    
        }else{
            temp[i]=temp[i-1];
        }
    }
    for(int i=0;i<m;i++){
        int l,r;cin>>l>>r;
        cout<<temp[r-1]-temp[l-1]<<endl;
    }

}
int main(){
    int t=1;
    while(t--){
        solve();
    }
}