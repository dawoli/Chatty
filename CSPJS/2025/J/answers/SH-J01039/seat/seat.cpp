#include <iostream>
#include <algorithm>
using namespace std;

int a[111];

int main() {
  freopen("seat.in", "r", stdin);
  freopen("seat.out", "w", stdout);

  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n * m; i++)
    cin >> a[i];
  int t = a[1];
  sort(a + 1, a + n * m + 1, greater<int>());
  int pos;
  for (int i = 1; i <= n * m; i++)
    if (a[i] == t) pos = i;
  int y = (pos + n - 1) / n;
  pos %= 2 * n;
  int x;
  if (!pos) x = 1;
  else if (pos <= n) x = pos;
  else if (pos > n) x = n - (pos - n) + 1;
  cout << y << ' ' << x;

  return 0;
}
