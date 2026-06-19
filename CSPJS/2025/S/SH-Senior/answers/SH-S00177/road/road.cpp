#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 +10, M = 2e6 +10;
int n, m, k;
int d[N];
struct edge{
    int u, v, len;
}edges[M];

bool cmp(edge a, edge b){
    if(a.len <= b.len){
        return true;
    }
    return false;
}

int find(int x){
    if(d[x] == x){
        return x;
    }else{
        return d[x] = find(d[x]);
    }
}

void merge(int x, int y)
{
    int xa = find(x);
    int ya = find(y);
    if(xa != ya){
        d[xa] = ya;
    }
}

void funa(){
    for(int i = 1; i <= n; i++){
        d[i] = i;
    }

    for(int i = 1; i <= m; i++){
        scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].len);
    }

    sort(edges + 1, edges + 1 + m, cmp);

    int sum = 0;
    for(int i = 1; i <= m; i++){
        edge E = edges[i];
        if(find(E.u) != find(E.v)){
            merge(E.u, E.v);
            sum += E.len;
        }
    }

    printf("%d\n", sum);
}

int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    scanf("%d%d%d", &n, &m, &k);

    funa();

    return 0;
}
