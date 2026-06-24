#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define vll vector<long long>
#define vd vector<double>
#define pii pair<int,int>
#define pll pair<long long,long long>
#define v(x) vector<x>
ll powmod(ll a,ll b,ll c){
    ll d=1;
    while(b>1){
        if(b%2==0){
            b=b/2;
        }else{
            b=b/2;
            d=(d*a)%c;
        }
        a=(a*a)%c;
    }
    a=(a*d)%c;
    return a;
}
void dfs(vector<vi>& adj,vi& dist,int node){
    int length=0;
    for(int i:adj[node-1]){
        if(dist[i]!=-1){
            length=max(length,dist[i]+1);
            continue;
        }
        dfs(adj,dist,i+1);
        length=max(dist[i]+1,length);
    }
    dist[node-1]=length;

}
void solve(){
    int n; 
    cin >> n;
    ll mod = 1e9 + 7;
    
    vector<vi> bits(n, vi(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> bits[i][j];
        }
    }
    
    // total_masks = 2^N
    int total_masks = 1 << n;
    
    // dp[mask] stores the number of ways to pair the first 'i' men 
    // with the subset of women represented by 'mask'
    vll dp(total_masks, 0);
    dp[0] = 1; // Base case: 1 way to pair 0 men with 0 women
    
    // Iterate through all possible subsets of women
    for (int mask = 0; mask < total_masks; mask++) {
        // The number of set bits tells us exactly which man we are matching
        int i = __builtin_popcount(mask); 
        
        // If all men are already matched, we don't need to process further from here
        if (i == n) continue; 
        
        // Try matching Man 'i' with an available Woman 'j'
        for (int j = 0; j < n; j++) {
            // Check if Woman 'j' is NOT yet chosen in this mask, 
            // and if Man 'i' is compatible with Woman 'j'
            if (!(mask & (1 << j)) && bits[i][j]) {
                int next_mask = mask | (1 << j);
                dp[next_mask] = (dp[next_mask] + dp[mask]) % mod;
            }
        }
    }
    
    // The answer is the configuration where all women are paired
    cout << dp[total_masks - 1] << "\n";
}
int main() {
    fastio;

    int t=1;
    //cin >> t; // number of test cases (if needed)
    while(t--) {
        solve();
    }

    return 0;
}