#include <bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int main()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin >> n;
	int c1 = 0, c2 = 0;
	for(int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	int l = 1;
	int ans = n;
	for(int i = 0;i < n;i++)
	{
		while(l < n && a[l] == a[i]) l++;
		if(l == n) break;
		ans--;
		l++;
	}
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//HF#24THMC
