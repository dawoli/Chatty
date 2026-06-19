#include <bits/stdc++.h>

using namespace std;


const int N = 209, NN = 109;
int n;
int a[N][4];
long long f[NN][NN][NN];  // 前i个人中，a个1部门，...，的最大满意度 


int main()
{
  freopen("club.in", "r", stdin);
  freopen("club.out", "w", stdout);
  
  int T;
  scanf("%d", &T);
  while (T --)
  {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
      for (int j = 1; j <= 3; j ++)
      {
        scanf("%d", &a[i][j]);
      }
    }
    
    memset(f, 0, sizeof(f));
    long long ans = 0;
    int emm = n / 2;
    for (int x = 0; x <= emm; x ++)
    {
      for (int y = 0; y <= emm; y ++)
      {
        for (int z = 0; z <= emm; z ++)
        {
          int i = x + y + z;
          if (i <= n)
          {
            if (x > 0) f[x][y][z] = max(f[x][y][z], f[x - 1][y][z] + a[i][1]);
            if (y > 0) f[x][y][z] = max(f[x][y][z], f[x][y - 1][z] + a[i][2]);
            if (z > 0) f[x][y][z] = max(f[x][y][z], f[x][y][z - 1] + a[i][3]);
            if (i == n) ans = max(ans, f[x][y][z]);
          }
        }
      }
    }
    printf("%lld\n", ans);
  }

  return 0;
}

