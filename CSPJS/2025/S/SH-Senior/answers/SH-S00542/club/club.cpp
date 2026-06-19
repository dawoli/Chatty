//Passed all samples!
#include <bits/stdc++.h>

using namespace std;
struct ps {
   int a1 = 0, a2 = 0, a3 = 0, mx, md, mn, id;
   ps(int a1, int a2, int a3, int id) {
      this->a1 = a1;
      this->a2 = a2;
      this->a3 = a3;
      this->id = id;
      mx = max(a1, max(a2, a3));
      mn = min(a1, min(a2, a3));
      if(mx == a1) {
         if(mn == a3) md = a2;
         else md = a3;
      } else if(mx == a2) {
         if(mn == a1) md = a3;
         else md = a1;
      } else if(mx == a3) {
         if(mn == a1) md = a2;
         else md = a1;
      }
   }
};
vector<ps> pd1, pd2, pd3;
bool sat[100005];
int cnt1, cnt2, cnt3;

bool sortbymax(ps a, ps b) {
   return a.mx - a.md > b.mx - b.md;
}
bool sortbymid(ps a, ps b) {
   return a.md - a.mn > b.md - b.mn;
}
bool sortbymin(ps a, ps b) {
   return a.mn > b.mn;
}

int main() {
   freopen("club.in", "r", stdin);
   freopen("club.out", "w", stdout);
   int t;
   cin >> t;
   for(int tcs = 1; tcs <= t; tcs++) {
      //Clear state
      int ans = 0;
      cnt1 = 0, cnt2 = 0, cnt3 = 0;
      pd1.clear();
      pd2.clear();
      pd3.clear();
      memset(sat, 0, sizeof(sat));
      int n;
      cin >> n;
      for(int i = 1; i <= n; i++) {
         int a1, a2, a3;
         cin >> a1 >> a2 >> a3;
         pd1.emplace_back(a1, a2, a3, i);
         pd2.emplace_back(a1, a2, a3, i);
         pd3.emplace_back(a1, a2, a3, i);
      }
      sort(pd1.begin(), pd1.end(), sortbymax);
      sort(pd2.begin(), pd2.end(), sortbymid);
      sort(pd3.begin(), pd3.end(), sortbymin);
      for(ps i : pd1) {
         if(sat[i.id]) continue;
         if(i.mx == i.a1 && cnt1 < n / 2) {
            cnt1++;
            sat[i.id] = true;
            ans += i.a1;
            continue;
         }
         if(i.mx == i.a2 && cnt2 < n / 2) {
            cnt2++;
            sat[i.id] = true;
            ans += i.a2;
            continue;
         }
         if(i.mx == i.a3 && cnt3 < n / 2) {
            cnt3++;
            sat[i.id] = true;
            ans += i.a3;
            continue;
         }
      }
      for(ps i : pd2) {
         if(sat[i.id]) continue;
         if(i.md == i.a1 && cnt1 < n / 2) {
            cnt1++;
            sat[i.id] = true;
            ans += i.a1;
            continue;
         }
         if(i.md == i.a2 && cnt2 < n / 2) {
            cnt2++;
            sat[i.id] = true;
            ans += i.a2;
            continue;
         }
         if(i.md == i.a3 && cnt3 < n / 2) {
            cnt3++;
            sat[i.id] = true;
            ans += i.a3;
            continue;
         }
      }
      for(ps i : pd3) {
         if(sat[i.id]) continue;
         if(i.mn == i.a1 && cnt1 < n / 2) {
            cnt1++;
            sat[i.id] = true;
            ans += i.a1;
            continue;
         }
         if(i.mn == i.a2 && cnt2 < n / 2) {
            cnt2++;
            sat[i.id] = true;
            ans += i.a2;
            continue;
         }
         if(i.mn == i.a3 && cnt3 < n / 2) {
            cnt3++;
            sat[i.id] = true;
            ans += i.a3;
            continue;
         }
      }
      cout << ans << endl;
   }
   return 0;
}
