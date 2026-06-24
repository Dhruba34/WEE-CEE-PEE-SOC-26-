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
    vector<vi> forest(n,vi(n,0));
    for(int i=0;i<n;i++){
        string s;cin>>s;
        for(int j=0;j<n;j++){
            if(s[j]=='.') forest[i][j]=0;
            else forest[i][j]=1;
        }
    }
    vector<vi> sums(n,vector<int>(n,0));
    sums[0][0]=forest[0][0];
    for(int i=1;i<n;i++){
        sums[0][i]=sums[0][i-1]+forest[0][i];
    }
    for(int i=1;i<n;i++){
        vi temp(n);
        temp[0]=forest[i][0];
        sums[i][0]=sums[i-1][0]+temp[0];
        for(int j=1;j<n;j++){
            temp[j]=temp[j-1]+forest[i][j];
            sums[i][j]=sums[i-1][j]+temp[j];
        }
    }
    vector<vi> sums2(n+1,vi(n+1,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            sums2[i+1][j+1]=sums[i][j];
        }
    }
    for(int i=0;i<q;i++){
        int r1,c1,r2,c2;cin>>r1>>c1>>r2>>c2;
        cout<<sums2[r2][c2]-sums2[r2][c1-1]-sums2[r1-1][c2]+sums2[r1-1][c1-1]<<endl;
    }
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
}