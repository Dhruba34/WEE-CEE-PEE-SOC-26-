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
void solve(){
    int n;cin>>n;
    vll arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(all(arr));
    int dist=1;
    for(int i=1;i<n;i++){
        if(arr[i]!=arr[i-1]) dist++;
    }
    cout<<dist<<endl;
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
}