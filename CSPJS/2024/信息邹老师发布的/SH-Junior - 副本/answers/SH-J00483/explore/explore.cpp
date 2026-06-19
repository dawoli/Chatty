#include <bits/stdc++.h>
using namespace std;

bool ma[1005][1005];
bool vis[1005][1005];
bool vis1[1005][1005][5];
long long n,m,k,xs,ys, ds, res=0;
char everyl[1005];

int drct[10][10] = {{0,1},{1,0},{0,-1},{-1,0}};

void dfs(int x, int y, int d, long long kcurr) {
    if (kcurr > k) return;
    int xnow = x+drct[d][0];
    int ynow = y+drct[d][1];
    if (xnow<1 || xnow>n || ynow<1 || ynow>m || !ma[xnow][ynow]) {
        dfs(x,y,(d+1)%4, kcurr+1);
        return;
    }
    vis[xnow][ynow]=1;
    if (!vis1[xnow][ynow][d]) {
    	vis1[xnow][ynow][d]=true;
    	dfs(xnow, ynow, d ,kcurr+1);
	}
    return;
}

int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin >> t;
    for (int i=1;i<=t;i++) {
        memset(vis,0,sizeof(vis));
        memset(vis1,0,sizeof(vis1));
        cin >> n >> m >> k >> xs >> ys >> ds;
        for (int j=1;j<=n;j++) {
            cin >> everyl;
            for (int k=0;k<m;k++) {
                if (everyl[k] == '.') ma[j][k+1]=1;
                else ma[j][k+1]=0;
            }
        }
        vis[xs][ys]=1;
        dfs(xs,ys,ds, 1);
        res=0;
        for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) if (vis[i][j]==1) res++;
        cout << res <<endl;
    }
    return 0;
}
