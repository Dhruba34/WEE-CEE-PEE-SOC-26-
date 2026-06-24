//olla to cp
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

// --- CUSTOM ORDER STATISTIC TREE (REPLACES PBDS MULTISET) ---
class CustomOrderedMultiset {
private:
    struct OSTNode {
        ll val;
        int count;
        int subtree_size;
        OSTNode* left;
        OSTNode* right;
        OSTNode(ll v) : val(v), count(1), subtree_size(1), left(nullptr), right(nullptr) {}
    };

    OSTNode* root;
    int total_elements;

    int getSize(OSTNode* node) { return node ? node->subtree_size : 0; }
    
    void updateSize(OSTNode* node) {
        if (node) node->subtree_size = node->count + getSize(node->left) + getSize(node->right);
    }

    OSTNode* insertHelper(OSTNode* node, ll val) {
        if (!node) return new OSTNode(val);
        if (val == node->val) node->count++;
        else if (val < node->val) node->left = insertHelper(node->left, val);
        else node->right = insertHelper(node->right, val);
        updateSize(node);
        return node;
    }

    int orderOfKeyHelper(OSTNode* node, ll val) {
        if (!node) return 0;
        if (val <= node->val) return orderOfKeyHelper(node->left, val);
        return node->count + getSize(node->left) + orderOfKeyHelper(node->right, val);
    }

public:
    CustomOrderedMultiset() : root(nullptr), total_elements(0) {}
    
    void insert(ll val) {
        root = insertHelper(root, val);
        total_elements++;
    }
    
    int order_of_key(ll val) {
        return orderOfKeyHelper(root, val);
    }
    
    int size() {
        return total_elements;
    }
};
#define ordered_multiset(x) CustomOrderedMultiset

ll mod=1e9+7;
vll fact(1e5,1);
vll factinv(1e5,1);
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
void factcal(int n,ll m){
    for(int i=2;i<=n;i++){
        fact[i]=(fact[i-1]*i)%m;
    }
}
void factinvcal(int n,ll m){
    for(int i=2;i<=n;i++){
        factinv[i]=powmod(fact[i],m-2,m);
    }
}
ll gcd(ll a,ll b){
    while(b%a){
        ll c=b%a;
        b=a;
        a=c;
    }
    return a;
}
ll lcm(ll a,ll b){
    return (a*b)/gcd(a,b);
}

void dfs(vector<vi>& adj,int cur,int p,v(vll)& dp){
    for(int i:adj[cur]){
        if(i==p) continue;
        dfs(adj,i,cur,dp);
        dp[cur][0]=(dp[cur][0]*(dp[i][0]+dp[i][1])%mod)%mod;
        dp[cur][1]=(dp[cur][1]*dp[i][0])%mod;
    }
}
struct Node {
    ll max_val;
    Node* left;
    Node* right;
    Node() {
        max_val = 0;
        left = nullptr;
        right = nullptr;
    }
};
int customfunc(int a,int b){
    return max(a,b);
}
/**
 * Dynamically inserts or updates a value in the tree
 * node  The current node pointer
 * start The virtual start boundary of this node (e.g., 1)
 * end   The virtual end boundary of this node (e.g., 10^9)
 * idx   The exact coordinate/value where the element is being placed
 * val   The DP value to store at that coordinate
 * all 1-indexed
 */
void update(Node* node, int start, int end, int idx, int val) {
    if (start == end) {
        node->max_val = customfunc(node->max_val, val);
        return;
    }

    int mid = start + (end - start) / 2;

    if (idx <= mid) {
        if (node->left == nullptr) {
            node->left = new Node();
        }
        update(node->left, start, mid, idx, val);
    } else {
        if (node->right == nullptr) {
            node->right = new Node();
        }
        update(node->right, mid + 1, end, idx, val);
    }
    ll left_val = (node->left != nullptr) ? node->left->max_val : 0;
    ll right_val = (node->right != nullptr) ? node->right->max_val : 0;
    node->max_val = customfunc(left_val, right_val);
}
ll query(Node* node, int start, int end, int L, int R) {
    if (node == nullptr || R < start || end < L) {
        return 0;
    }
    if (L <= start && end <= R) {
        return node->max_val;
    }
    int mid = start + (end - start) / 2;
    ll left_res = query(node->left, start, mid, L, R);
    ll right_res = query(node->right, mid + 1, end, L, R);
    
    return customfunc(left_res, right_res);
}
ll maxn=1e6;
v(vi) divide(maxn+1);
void divisors(){
    for(int i=1;i<=maxn;i++){
        for(int j=i;j<=maxn;j+=i){
            divide[j].pb(i);
        }
    }
    //generates all divisors for numbers upto maxn
}
//bye to cp
int func(ll l,int n,vi& a,vi& tmp,v(vi)& store){
    if(l<=n){
        return a[l-1];
    }
    if(l/2>n){
        if((l/2)%2==0){
            int again=func(l/2,n,a,tmp,store);
            int again2=func(2*(l/2-1),n,a,tmp,store);
            return again^again2;
        }
        int rem=((l/2)-n)%4-1;
        vi tmp2=tmp;
        if(rem>=0){
            for(int i=0;i<n;i++){
                tmp2[i]=(tmp[i]+store[i][rem])%2;
            }
        }
        /**cout<<"#"<<l<<endl;
        for(int i=0;i<n;i++){
            cout<<tmp2[i]<<" ";
        }
        cout<<endl;*/
        int ans=0;
        for(int i=0;i<n;i++){
            if(tmp2[i]){
                ans=ans^a[i];
            }
        }
        return ans;
    }else{
        vi tmp2=tmp;
        for(int i=l/2;i<n;i++){
            tmp2[i]--;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(tmp2[i]){
                ans=ans^a[i];
            }
        }
        return ans;
    }
}
void solve(){
    int n;ll l,r;cin>>n>>l>>r;
    vi a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vi tmp(n,1);
    v(vi) store(n,vi(3));
    for(int i=0;i<n;i++){
        if(i+1<=(n+1)/2){
            store[i][0]=1;
        }else{
            store[i][0]=0;
        }
        if(i+1<=(n+2)/2){
            store[i][1]=1;
        }else{
            store[i][1]=0;
        }
        if(n==1){
            store[i][2]=0;
        }else if(i+1<=(n+3)/2){
            store[i][2]=1;
        }else{
            store[i][2]=0;
        }
    }
    /**for(int i=0;i<n;i++){
        cout<<store[i][0]<<" "<<store[i][1]<<" "<<store[i][2]<<endl;
    }*/
    for(int i=0;i<n;i++){
        store[i][1]=(store[i][1]+store[i][0])%2;
        store[i][2]=(store[i][2]+store[i][1])%2;
    }
    cout<<func(l,n,a,tmp,store)<<endl;
    
}

int main() {
    fastio;
    divisors();
    int t;
    cin >> t; // number of test cases (if needed)
    while(t--) {
        solve();
    }

    return 0;
}