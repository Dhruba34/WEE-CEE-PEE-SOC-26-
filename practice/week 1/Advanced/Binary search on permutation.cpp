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
    int n,x;cin>>n>>x;
    vi p(n);int xpos=0;
    for(int i=0;i<n;i++){
        cin>>p[i];
        if(p[i]==x){
            xpos=i;
        }
    }
    if(n==1){
        cout<<0<<endl;
        return;
    }
    int l=0;int r=n;
    vector<vi> ans;
    if(p[(l+r)/2]==x){
        while(r-l!=1){
            int mid=(l+r)/2;
            if(p[mid]<=x){
                l=mid;
            }else{
                r=mid;
            }
        }
        if(p[l]==x){
            cout<<0<<endl;
            return;
        }else{
            ans.push_back({xpos+1,l+1});
        }
    }else{
        int cur=xpos;
        if(p[(l+r)/2]<x && xpos>(l+r)/2){
            ans.push_back({1,xpos+1});
            int c=p[0];
            p[0]=p[xpos];
            p[xpos]=c;
            cur=0;
        }else if(p[(l+r)/2]>x && xpos<(l+r)/2){
            ans.push_back({n,xpos+1});
            int c=p[n-1];
            p[n-1]=p[xpos];
            p[xpos]=c;
            cur=n-1;
        }
        while(r-l!=1){
            int mid=(l+r)/2;
            if(p[mid]<=x){
                l=mid;
            }else{
                r=mid;
            }
        }
        ans.push_back({cur+1,l+1});
    }
    cout<<ans.size()<<endl;
    for(auto v:ans){
        cout<<v[0]<<" "<<v[1]<<endl;
    }
}
int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
}