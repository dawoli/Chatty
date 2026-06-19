#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int seq[N];

int main()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	int n, maxn = 0, minn = INT_MAX;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		seq[tmp] += 1;
		maxn = max(maxn, tmp);
		minn = min(minn, tmp);
	}
	if (maxn == minn)
	{
		cout << 1 << endl;
		return 0;
	}
	
	int total = seq[maxn];
	for (int i = maxn - 1; i >= minn; i--)
	{
		if (seq[i] >= total) // more low level monsters 
		{
			seq[i] -= total;
			total += seq[i];
		}
		else // more high level monsters
			seq[i] = total - seq[i];
	}
	cout << total << endl;
	return 0;
} 
