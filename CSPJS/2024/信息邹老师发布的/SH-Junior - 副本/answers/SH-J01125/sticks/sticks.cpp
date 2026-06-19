#include <bits/stdc++.h>

using namespace std;


int a[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};  // 数字i的木棍数
int b[] = {1, 2, 0, 8};  // 用来凑的数 
int c[] = {-1, -1, 1, 7, 4, 2, 6, 8};  // 答案 


inline int div7(int n)
{
  return ceil(n / 7.0);
}


int main()
{
  freopen("sticks.in", "r", stdin);
  freopen("sticks.out", "w", stdout);
  
  int T;
  scanf("%d", &T);
  while (T --)
  {
    int n;
    scanf("%d", &n);
    
    if (n <= 7)
    {
      printf("%d\n", c[n]);
    }
    else
    {
      int dig = div7(n);
      for (int i = 1; i <= dig; i ++)
      {
        for (int j = 0; j < 4; j ++)
        {
          if (div7(n - a[b[j]]) == dig - i)
          {
            if (i == 1 && b[j] == 0)
            {
              printf("6");
            }
            else
            {
              printf("%d", b[j]);
            }
            n -= a[b[j]];
            break;
          }
        }
      }
      printf("\n"); 
    }
  }

  return 0;
}

