#include<bits/stdc++.h>
using namespace std;
#define maxn 523456
#define maxn2 1234567
struct node{
    int l, r;
    node(){}
    node(int al, int ar){
        l = al; r = ar;
    }
} b[maxn2];
int n, k, a[maxn], s[maxn], p, cur, ans;
bool cmp(node x, node y){
    if(x.r != y.r) return x.r < y.r;
    return x.l < y.l;
}
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        s[i] = s[i-1] ^ a[i];
    }
    p = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            if((s[j] ^ s[i-1]) == k){
                b[p] = node(i, j);
                p++;
            }
        }
    }
    sort(b, b + p, cmp);
    cur = 0;
    for(int i = 0; i < p; i++){
        if(b[i].l > cur){
            cur = b[i].r;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}