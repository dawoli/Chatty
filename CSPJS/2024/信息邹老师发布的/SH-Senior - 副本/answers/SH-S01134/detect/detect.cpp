#include <bits/stdc++.h>

using namespace std;


const int N = 1e5 + 9, ML = 1e6 + 9;
int n, m, L, V, d[N], v[N], a[N], p[N];
int need[N], st[N], ed[N];  // 某个点的超速车数量、超速开始、超速结束
vector <int> over[N];  // 某个点上超速的车
bool ok[N];  // 能拍到超速（或没有超速） 


inline void add(int i, int s, int e)
{
  st[i] = s;
  ed[i] = e;
  for (int j = s; j <= e; j ++)
  {
//    printf("%d ", p[j]);
    over[j].push_back(i);
    need[j] ++;
  }
//  printf("\n");
}


int main()
{
  freopen("detect.in", "r", stdin);
  freopen("detect.out", "w", stdout);
  
  int T;
  scanf("%d", &T);
  while (T --)
  {
    memset(ok, 0, sizeof(ok));
    
    scanf("%d %d %d %d", &n, &m, &L, &V);
    for (int i = 1; i <= n; i ++)
    {
      scanf("%d %d %d", &d[i], &v[i], &a[i]);
    }
    for (int i = 1; i <= m; i ++)
    {
      scanf("%d", &p[i]);
    }
    
    int cnt = 0, okc = 0;
    for (int i = 1; i <= n; i ++)
    {
      if (a[i] == 0)
      {
        if (v[i] > V)
        {
          int le = lower_bound(p + 1, p + m + 1, d[i]) - p, ri = m;
          if (ri <= L)
          {
            cnt ++;
            add(i, le, ri);
          }
        }
        else
        {
          ok[i] = true;
          okc ++;
        }
      }
      else if (a[i] > 0)
      {
      }
      else
      {
      }
    }
    printf("%d ", cnt);
    
    int ans = 0;
    while (okc < n)
    {
      int p = max_element(need + 1, need + m + 1) - need;
      for (auto i : over[p])
      {
        if (!ok[i])
        {
          ok[i] = true;
          okc ++;
        }
        for (int j = st[i]; j <= ed[i]; j ++)
        {
          need[j] --;
        }
      }
      ans ++;
    }
    printf("%d\n", m - ans);
  }

  return 0;
}

