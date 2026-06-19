#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define all(x) x.begin(), x.end()

using ull=uint64_t;
using ll=int64_t;

array<int, 100005> nm;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  freopen("duel.in", "r", stdin);
  freopen("duel.out", "w", stdout);

  int n; cin>>n;

  int r;
  for (int i=0; i<n; ++i) {
    cin>>r;
    ++nm[r];
  }

  cout<<*max_element(all(nm))<<endl;

  return 0;
}
