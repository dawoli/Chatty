#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int read() {
    int f=1,x=0;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-'){f=-1;}ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return f*x;
}

const int MAXN = 1e5 + 5;
int t, n, x, y, z, ans;
vector<int> a, b, c;

int solve() {
    n = read(); ans = 0;
    a.clear(), b.clear(), c.clear();
    for (int i = 1; i <= n; ++i) {
        x = read(); y = read(); z = read();
        ans += max(x, max(y, z));
        if (x >= y && y >= z) a.push_back(x - y);
        else if (x >= z && z >= y) a.push_back(x - z);
        else if (y >= x && x >= z) b.push_back(y - x);
        else if (y >= z && z >= x) b.push_back(y - z);
        else if (z >= x && x >= y) c.push_back(z - x);
        else if (z >= y && y >= x) c.push_back(z - y);
    }
    if ((int)a.size() > n / 2) {
        int diff = a.size() - n / 2;
        sort(a.begin(), a.end(), less<int>());
        for (int i = 0; i < diff; ++i) {
            ans -= a[i];
        }
    }
    if ((int)b.size() > n / 2) {
        int diff = b.size() - n / 2;
        sort(b.begin(), b.end(), less<int>());
        for (int i = 0; i < diff; ++i) {
            ans -= b[i];
        }
    }
    if ((int)c.size() > n / 2) {
        int diff = c.size() - n / 2;
        sort(c.begin(), c.end(), less<int>());
        for (int i = 0; i < diff; ++i) {
            ans -= c[i];
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    t = read();
    while (t--) {
        cout << solve() << '\n';
    }
    return 0;
}