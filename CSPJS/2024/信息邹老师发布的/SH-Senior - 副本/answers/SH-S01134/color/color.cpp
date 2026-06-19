#include <bits/stdc++.h>

using namespace std;


const int N = 2e5 + 9;
int n, a[N];
long long ans;
int co[N];  // 1:À¶É« 2:ºìÉ« 


void dfs(int p)
{
  if (p > n)
  {
    long long c = 0;
    for (int i = 1; i <= n; i ++)
    {
      for (int j = i - 1; j >= 1; j --)
      {
        if (co[i] == co[j])
        {
//          printf("%d == %d\n", i, j);
          if (a[i] == a[j])
          {
            c += a[i];
          }
          break;
        }
      }
    }
//    for (int i = 1; i <= n; i ++)
//    {
//      printf("%d", co[i]);
//    }
//    printf(" %lld\n", c);
    ans = max(ans, c);
    return;
  }

  co[p] = 1;
  dfs(p + 1);
  co[p] = 2;
  dfs(p + 1);
}


int main()
{
  freopen("color.in", "r", stdin);
  freopen("color.out", "w", stdout);
  
  int T;
  scanf("%d", &T);
  while (T --)
  {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
      scanf("%d", &a[i]);
    }
    ans = 0;
    dfs(1);
    printf("%lld\n", ans);
  }

  return 0;
}

