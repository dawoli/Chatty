#include <iostream>
using namespace std;
int m, n, a[102][102];
void zuoyou() {
 for (int i = 1; i <= n; i++)
  for (int j = 1; j <= m / 2; j++)
   swap(a[i][j], a[i][m - j + 1]);
 return;
}
void shangxia() {
 for (int i = 1; i <= n / 2; i++)
  for (int j = 1; j <= m; j++)
   swap(a[i][j], a[n - i + 1][j]);
 return;
}
int main() {
 cin >> n >> m;
 for (int i = 1; i <= n; i++)
  for (int j = 1; j <= m; j++)
   cin >> a[i][j];
 zuoyou();
 for (int i = 1; i <= n; i++) {
  for (int j = 1; j <= m; j++)
   cout << a[i][j] << " ";
  cout << endl;
 }
 return 0;
}
 
