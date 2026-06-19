#include <bits/stdc++.h>
using namespace std;

using ull=uint64_t;
using ll=int64_t;

constexpr ull MAX=0x7f7f7f7f7f7f7f7fULL;

ull a[100000];

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  freopen("color.in", "r", stdin);
  freopen("color.out", "w", stdout);

  int T; cin>>T;
  while (T--) {
    int n; cin>>n;
    ull ans=0;
    for (int i=0; i<n; ++i) cin>>a[i];
    for (ull i=0; i<(1ULL<<n); ++i) {
      ull cnt=0;
      ull lb=0, lr=0;
      for (int j=0; j<n; ++j) {
        if ((i&(1ULL<<j))==1) { // blue
          if (lb==a[j]) cnt+=lb;
          lb=a[j];
        } else {
          if (lr==a[j]) cnt+=lr;
          lr=a[j];
        }
      }
      ans=max(ans, cnt);
    }
    cout<<ans<<"\n";
  }

  return 0;
}
