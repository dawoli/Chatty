#include <bits/stdc++.h>

using namespace std;


const int N = 2e5 + 9;
int n, q;
string s[N][3], t[N][3];


bool match(string a, string b, int k)
{
  for (int i = 0; i < b.size(); i ++)
  {
    if (a[i + k] != b[i])
    {
      return false;
    }
  }
  return true;
}


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  
  cin >> n >> q;
  for (int i = 1; i <= n; i ++)
  {
    cin >> s[i][1] >> s[i][2];
  }
  
  for (int i = 1; i <= q; i ++)
  {
    cin >> t[i][1] >> t[i][2];
//    cout << t[i][1] << '\n';
    if (t[i][1].size() != t[i][2].size())
    {
      printf("0\n");
      continue;
    }
    long long ans = 0;
    int tlen = t[i][1].size();
    for (int j = 1; j <= n; j ++)
    {
      int slen = s[j][1].size();
      for (int k = 0; k <= tlen - slen; k ++)
      {
        if (match(t[i][1], s[j][1], k))
        {
          string tmp = t[i][1].substr(0, k) + s[j][2] + t[i][1].substr(k + slen);
//          cout << ' ' << tmp << '\n'; 
          if (tmp == t[i][2])
          {
            ans ++;
          }
        }
      }
    }
    cout << ans << '\n';
  }

  return 0;
}

