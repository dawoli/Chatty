#include <bits/stdc++.h>

using namespace std;


const int N = 1e3 + 9;
int n, m, k, x, y, d;
char a[N][N];
bool vst[N][N];


int main()
{
  freopen("explore.in", "r", stdin);
  freopen("explore.out", "w", stdout);
  
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  int T;
  cin >> T;
  while (T --)
  {
    cin >> n >> m >> k >> x >> y >> d;
    for (int i = 1; i <= n; i ++)
    {
      for (int j = 1; j <= m; j ++)
      {
        cin >> a[i][j];
      }
    }
    
    memset(vst, false, sizeof(vst));
    vst[x][y] = true;
    int cnt = 1;
    while (k --)
    {
      int dx = x, dy = y;
      switch (d)
      {
        case 0:
          dy ++;
          break;
        case 1:
          dx ++;
          break;
        case 2:
          dy --;
          break;
        case 3:
          dx --;
          break;
      }
      if (dx >= 1 && dx <= n && dy >= 1 && dy <= m && a[dx][dy] == '.')
      {
        x = dx, y = dy;
        if (!vst[x][y])
        {
          cnt ++;
          vst[x][y] = true;
        }
      }
      else
      {
        d = (d + 1) % 4;
      }
    }
    cout << cnt << endl;
  }

  return 0;
}

