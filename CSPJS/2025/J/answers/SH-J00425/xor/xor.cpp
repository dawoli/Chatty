#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, k, a[N], sum[N], ans;
struct Node
{
    int l, r;
};
vector<Node> qujian;
bool cmp(const Node &A, const Node &B)
{
    if (A.r == B.r)
        return A.l > B.l;
    return A.r < B.r;
}
signed main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i], sum[i] = sum[i - 1] ^ a[i];
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            cnt++;
            if ((sum[j] ^ sum[i - 1]) == k)
            {
                qujian.push_back({i, j});
                break;
            }
            if (cnt >= 1e8)
                break;
        }
    }
    sort(qujian.begin(), qujian.end(), cmp);
    int last = 0;
    for (auto it : qujian)
    {
        if (it.l > last)
        {
            last = it.r;
            ans++;
        }
    }
    cout << ans;
}
// 70
