#include <bits/stdc++.h>

using namespace std;


const int N = 509, MOD = 998244353;
int n, m, s[N], c[N];
char s_in[N];

int a[N];
bool vst[N];
long long ans;


void dfs(int x)  // µÚxÌì 
{
  if (x == n)
  {
    int yes = 0, no = 0;
    for (int i = 1; i <= n; i ++)
    {
      if (s[i] == 0 || no >= c[a[i]])
      {
        no ++;
      }
      else
      {
        yes ++;
        if (yes == m)
        {
          ans = (ans + 1) % MOD;
          return;
        }
      }
    }
    return;
  }
  
  for (int i = 1; i <= n; i ++)
  {
    if (!vst[i])
    {
      vst[i] = true;
      a[x + 1] = i;
      dfs(x + 1);
      vst[i] = false;
    }
  }
}


int main()
{
  freopen("employ.in", "r", stdin);
  freopen("employ.out", "w", stdout);
  
  scanf("%d %d %s", &n, &m, s_in);
  for (int i = 1; i <= n; i ++)
  {
    s[i] = s_in[i - 1] - '0';
    scanf("%d", &c[i]);
  }
  
  if (n <= 10)
  {
    dfs(0);
    printf("%lld\n", ans);
  }
  else
  {
    printf("0\n");
  }

  return 0;
}

