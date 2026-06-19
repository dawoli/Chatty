#include <iostream>
#include <queue>
#include <vector>

int ls[150000007], rs[150000007], val[150000007], nodecnt;
int modify(int p, int l, int r, int i, int d) {
  int q = ++nodecnt, mid = (l + r) >> 1;
  if (l == r) {
    val[q] = d;
  } else {
    ls[q] = (i <= mid) ? modify(ls[p], l, mid, i, d) : ls[p];
    rs[q] = (i > mid) ? modify(rs[p], mid + 1, r, i, d) : rs[p];
  }
  return q;
}
int query(int p, int l, int r, int i) {
  int mid = (l + r) >> 1;
  if (l == r) {
    return val[p];
  }
  return (i <= mid) ? query(ls[p], l, mid, i) : query(rs[p], mid + 1, r, i);
}
int modify(int p, int i, int d) { return modify(p, 0, 675, i, d); }
int query(int p, int i) { return query(p, 0, 675, i); }
void dfs(int p, int l, int r, std::vector<std::pair<int, int>>& v) {
  int mid = (l + r) >> 1;
  if (l == r) {
    v.push_back({mid, val[p]});
    return;
  }
  if (ls[p]) {
    dfs(ls[p], l, mid, v);
  }
  if (rs[p]) {
    dfs(rs[p], mid + 1, r, v);
  }
}
std::vector<std::pair<int, int>> pos(int p) {
  std::vector<std::pair<int, int>> v;
  dfs(p, 0, 675, v);
  return v;
} 

int n, q;
int trie[5000007], fail[5000007], dep[5000007], sz[5000007], trieNode = 1;
void insert(std::string s, std::string t) {
  int p = 1;
  for (int i = 0; i < int(s.size()); ++i) {
    int x = (s[i] - 'a') * 26 + (t[i] - 'a');
    int q = query(trie[p], x);
    if (q == 0) {
      trie[p] = modify(trie[p], x, q = ++trieNode);
      dep[q] = dep[p] + 1;
    }
    p = q;
  }
  ++sz[p];
}
void ACAM() {
  std::queue<int> Q;
  for (auto [c, p] : pos(trie[1])) {
    Q.push(p);
    fail[p] = (c % 27 == 0);
  }
  for (int i = 0; i <= 675; i += 27) {
    if (query(trie[1], i) == 0) {
      trie[1] = modify(trie[1], i, 1);
    }
  }
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    int z = trie[fail[u]];
    auto E = pos(trie[u]);
    for (auto [c, p] : E) {
      z = modify(z, c, p);
    }
    trie[u] = z;
    for (auto [c, p] : E) {
      fail[p] = query(trie[fail[u]], c);
      Q.push(p);
    }
    sz[u] += sz[fail[u]];
  }
}

int main() {
  std::freopen("replace.in", "r", stdin);
  std::freopen("replace.out", "w", stdout);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    std::string s, t;
    std::cin >> s >> t;
    insert(s, t);
  }
  ACAM();
  while (q--) {
    std::string s, t;
    std::cin >> s >> t;
    int L = 0, R = 0;
    while (L < int(s.size()) && s[L] == t[L]) {
      ++L;
    }
    while (R < int(s.size()) && s[int(s.size()) - 1 - R] == t[int(t.size()) - 1 - R]) {
      ++R;
    }
    int p = 1;
    long long ans = 0;
    for (int i = 0; i < int(s.size()); ++i) {
      p = query(trie[p], (s[i] - 'a') * 26 + (t[i] - 'a'));
      if (p == 0) {
        break;
      }
      if (i + 1 - dep[p] <= L && int(s.size()) - 1 - i <= R) {
        ans += sz[p];
      }
    }
    std::cout << ans << '\n';
  }
  return 0;
}