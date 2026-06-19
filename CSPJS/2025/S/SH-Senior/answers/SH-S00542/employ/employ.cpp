#include <bits/stdc++.h>

using namespace std;
string dif;
int n, m, ans;
int c[100005], curep, currj;
int curc[10005], vis[10005];
void dfs(int day) {
   int cep = curep, crj = currj;
   if(currj >= c[curc[day]]) {
      currj++;
   } else if(dif[day] == '1') {
      curep++;
   } else currj++;
   if(day == n) {
      if(curep >= m)
         ans++;
      return;
   }
   for(int i = 1; i <= n; i++) {
      if(!vis[i]) {
         vis[i] = true;
         curc[day + 1] = i;
         dfs(day + 1);
         vis[i] = false;
      }
   }
   curep = cep, currj = crj;
}

int main() {
   freopen("employ.in", "r", stdin);
   freopen("employ.out", "w", stdout);
   cin >> n >> m;
   cin >> dif;
   dif = "0" + dif;
   for(int i = 1; i <= n; i++) {
      cin >> c[i];
   }
   for(int i = 1; i <= n; i++) {
      if(!vis[i]) {
         vis[i] = true;
         curc[1] = i;
         dfs(1);
         vis[i] = false;
      }
   }
   cout << ans << endl;
   return 0;
}
