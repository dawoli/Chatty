#include <bits/stdc++.h>

using namespace std;


const int N = 1e5 + 9;
int n, r[N];
int cnt[N];
set <int> a;
int used[N];  // 攻击力为i的攻击次数 


int main()
{
  freopen("duel.in", "r", stdin);
  freopen("duel.out", "w", stdout);
  
  scanf("%d", &n);
  for (int i = 1; i <= n; i ++)
  {
    scanf("%d", &r[i]);
    a.insert(r[i]);
    cnt[r[i]] ++;
  }
  if (a.size() == 1)
  {
    printf("%d\n", n);
    return 0;
  }
  
  int ans = n;
  set <int>::iterator p = a.begin(), pp = a.begin();
  pp ++;
  while (true)
  {
    while (cnt[*p] > 0)
    {
      cnt[*p] --;
      ans --;
      used[*pp] ++;
      
//      printf("%d->%d ", *pp, *p);
//      for (auto i : a)
//      {
//        printf(" %d", cnt[i]);
//      }
//      printf(" /");
//      for (auto i : a)
//      {
//        printf(" %d", used[i]);
//      }
//      printf("\n");
      
      if (used[*pp] == cnt[*pp])
      {
//        printf("! %d & %d !\n", *pp, *a.end());
        pp ++;
        if (*pp == *a.end())
        {
          printf("%d\n", ans);
          return 0;
        }
      }
    }
    p ++;
    if (p == pp)
    {
      pp ++;
      if (*pp == *a.end())
      {
        printf("%d\n", ans);
        return 0;
      }
    }
  }

  return 0;
}

