#include <bits/stdc++.h>
using namespace std;
const int MAXn = 1e5 + 9;
vector<int> d;

int main() {
    // When n == 1, what's the correct answer?
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for(int i = 1, ia; i <= n; i ++)
        scanf("%d", &ia), d.push_back(ia);
    d.push_back(-1);
    sort(d.begin(), d.end());
    int l = 1, r = 2;
    int killed = 0;
    while(r <= n) {
        while(r < n && d[l] == d[r]) r ++;
        if(r <= n && d[l] != d[r]) killed ++;
        l ++, r ++;
    }
    printf("%d", n - killed);
    return 0;
}
