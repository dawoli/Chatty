#include <bits/stdc++.h>

using namespace std;


const int N = 1e4 + 9, M = 1e6 + 9;
int n, m, k;
struct edge
{
  int u, v;
  long long w;
} e[M];
int fa[N];
long long ans;


bool cmp(edge x, edge y)
{
  return x.w < y.w;
}


int find(int x)
{
  if (fa[x] == x)
  {
    return x;
  }
  fa[x] = find(fa[x]);
  return fa[x];
}


int main()
{
  freopen("road.in", "r", stdin);
  freopen("road.out", "w", stdout);
  
  scanf("%d %d %d", &n, &m, &k);
  if (k > 0)
  {
    printf("0\n");
    return 0;
  }
  for (int i = 1; i <= m; i ++)
  {
    scanf("%d %d %lld", &e[i].u, &e[i].v, &e[i].w);
  }
  for (int i = 1; i <= n; i ++)
  {
    fa[i] = i;
  }
  sort(e + 1, e + m + 1, cmp);
  for (int i = 1; i <= m; i ++)
  {
    int u = e[i].u, v = e[i].v;
    int fu = find(u), fv = find(v);
//    printf("fa[%d] = %d, fa[%d] = %d\n", u, fu, v, fv);
    if (fu != fv)
    {
      fa[fu] = fv;
      ans += e[i].w;
    }
  }
  printf("%lld\n", ans);

  return 0;
}

