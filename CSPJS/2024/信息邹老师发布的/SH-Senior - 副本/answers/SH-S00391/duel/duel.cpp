#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int a[100005],box[100005];

int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		box[a[i]]++;
		ans = max(ans,box[a[i]]);
	}
	cout << ans << endl;
	return 0;
}
