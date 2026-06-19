#include <bits/stdc++.h>
using namespace std;
int f[1000005],ans,cnt,c[20],a[1000005],n,m,k;
struct Edge{
    int u,v,w;
}edge[1000005];
int find(int x){
    if(f[x] == x) return x;
    return f[x] = find(f[x]);
}
bool cmp(Edge A,Edge B){
    return A.w < B.w;
}
void kruskal(){
    sort(edge+1,edge+m+1,cmp);
    for(int i = 1; i <= m; i++){
        int eu = find(edge[i].u),ev = find(edge[i].v);
        if(eu == ev) continue;
        ans += edge[i].w;
        f[eu] = ev;
        if(++cnt == n-1){
            break;
        }
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        f[i] = i;
    }
    for(int i = 1; i <= m; i++){
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
    }
    for(int i = 1; i <= k; i++){
        cin >> c[i];
        for(int j = 1; j <= n; j++){
            cin >> a[j];
        }
    }
    kruskal();
    cout << ans;
    return 0;
}
