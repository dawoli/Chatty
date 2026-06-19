#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n, a[5005];
int f[5005];
bool cmp(int x1, int y1)
{
	return x1 > y1;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	f[0] = 1;
	for(int i = 1; i <= 5004; i++)
	{
		f[i] = f[i - 1] * i;
	}
	cin >> n;
	int maxx = -1;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		maxx = max(maxx, a[i]);
	}
	if(maxx == 1)
	{
		int ans = 0;
		for(int i = 3; i <= n ; i++)
		{
			ans += f[n] / f[i] / f[n - i];
		}
		cout << ans;
		return 0;
	}
	sort(a + 1, a + n + 1, cmp);
	if(2 * a[1] < a[1] + a[2] + a[3])
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	return 0;
 } 
 
/*



*/
