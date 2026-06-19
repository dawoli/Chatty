#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, k;
int fa[10005];
int find(int t) {
   if(fa[t] == t) return t;
   return fa[t] = find(fa[t]);
}
void merge(int x, int y) {
   if(find(x) != find(y)) {
      fa[fa[x]] = fa[y];
   }
}
struct eg {
   int u, v, c;
   eg(int u, int v, int c) {
      this->u = u, this->v = v, this->c = c;
   }
};
bool cmp(eg a, eg b) {
   return a.c < b.c;
}
vector<eg> edges;
int rurConnCst[11][10005];
map<pair<int, int>, int>pdc;
signed main() {
   ios_base::sync_with_stdio(false);
   freopen("road.in", "r", stdin);
   freopen("road.out", "w", stdout);
   cin >> n >> m >> k;
   if(k == 0) {
      //Kruskal time!
      for(int i = 1; i <= n; i++) {
         fa[i] = i;//init
      }
      for(int i = 1; i <= m; i++) {
         int u, v, w;
         cin >> u >> v >> w;
         edges.emplace_back(u, v, w);
      }
      sort(edges.begin(), edges.end(), cmp);
      int ans = 0;
      for(eg i : edges) {
         if(find(i.u) == find(i.v)) {
            continue;
         }
         merge(i.u, i.v);
         ans += i.c;
      }
      cout << ans << endl;
   } else {
      for(int i = 1; i <= n; i++) {
         fa[i] = i;//init
      }
      for(int i = 1; i <= m; i++) {
         int u, v, w;
         cin >> u >> v >> w;
         edges.emplace_back(u, v, w);
      }
      int zp[11], minv[11], c[11];
      for(int i = 1; i <= k; i++) zp[i] = -1, minv[i] = numeric_limits<int>::max();
      bool special = true;
      for(int i = 1; i <= k; i++) {
         cin >> c[i];
         if(c[i] != 0) special = false;
         for(int j = 1; j <= n; j++) {
            cin >> rurConnCst[i][j];
            if(rurConnCst[i][j] < minv[i]) {
               zp[i] = j;
               minv[i] = rurConnCst[i][j];
            }
         }
         if(minv[i] > 0) special = false;
      }
      if(special) {
         for(int i = 1; i <= k; i++) {
            for(int j = 1; j <= n; j++) {
               if(j != zp[i]) {
                  edges.emplace_back(zp[i], j, rurConnCst[i][j]);
               }
            }
         }
         sort(edges.begin(), edges.end(), cmp);
         long long ans = 0;
         for(eg i : edges) {
            if(find(i.u) == find(i.v)) {
               continue;
            }
            merge(i.u, i.v);
            ans += i.c;
         }
         cout << ans << endl;
      } else {
         for(int i = 1; i <= k; i++) {
            vector<int> mps;
            for(int j = 1; j <= n; j++) {
               if(rurConnCst[i][j] == minv[i]) {
                  mps.emplace_back(j);
               }
            }
            for(auto p : mps) {
               for(int j = 1; j <= n; j++) {
                  if(j != p) {
                     edges.emplace_back(p, -j, rurConnCst[i][j] + rurConnCst[i][p] + c[i]);
                     pdc[make_pair(p, j)] = c[i];
                  }
               }
            }
         }
         sort(edges.begin(), edges.end(), cmp);
         long long ans = 0;
         for(eg i : edges) {
            if(i.u < 0 || i.v < 0) {
               i.u = abs(i.u), i.v = abs(i.v);
               if(pdc.count(make_pair(i.u, i.v)) && pdc[make_pair(i.u, i.v)] > 0) {
                  i.c -= pdc[make_pair(i.u, i.v)];
                  pdc[make_pair(i.u, i.v)] = 0;
               }
            }
            if(find(i.u) == find(i.v)) {
               continue;
            }
            merge(i.u, i.v);
            ans += i.c;
         }
         cout << ans << endl;
      }
   }
   return 0;
}
