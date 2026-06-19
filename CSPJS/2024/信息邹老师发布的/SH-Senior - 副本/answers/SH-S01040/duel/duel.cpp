#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int a[N];

int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    priority_queue<int, vector<int>, greater<int>> q;
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n +1);
    for(int i = 1; i <= n; ++i) {
    	if(!q.empty() && q.top() < a[i]) q.pop();
    	q.push(a[i]);
    }
    cout << q.size();
    return 0;
}
