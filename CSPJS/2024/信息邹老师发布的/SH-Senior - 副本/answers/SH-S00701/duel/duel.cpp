#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int r[N];

int main(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &r[i]);
	sort(r + 1, r + n + 1);
	int cnt = 0, cur = n;
	for (int i = n; i >= 1; i--)
	{
		while (r[i] <= r[cur]) cur--;
		if (cur != 0)
		{
			cnt++;
			cur--;
		}
		if (cur == 0) break;
	}
	cout << n - cnt << endl;
	return 0;
}
