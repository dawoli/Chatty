//duel
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, a[N];

int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    int mx = 0, nw = 0;
    for(int i = 1; i <= n; ++ i){
        if(a[i] != a[i-1]){
            mx = max(mx, nw);
            nw = 1;
        } else {
            ++ nw;
        }
    }
    mx = max(mx, nw);
    printf("%d\n", mx);
    return 0;
}