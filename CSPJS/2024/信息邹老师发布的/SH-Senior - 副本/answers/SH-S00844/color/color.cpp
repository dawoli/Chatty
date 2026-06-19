#include <iostream>
using namespace std;
const int N = 2e5+10;
int T;
int n , a[N] , f[N][2];
inline void solve()
{
	cin >> n;
	for(int i =1;i <= n;i++) cin >> a[i];
	
	for(int i = 2;i<=n;i++)
	{
		for(int j = i-1;j>=1;j--)
		{
			if(a[i] == a[j])
			{
				if(j == i-1)
				{
					f[i][0] = max(f[j][0] + a[i]  , f[i][0]);
					f[i][1] = max(f[j][1] + a[i]  , f[i][1]);
				}
				else
				{
					f[i][0] = max(f[j][0] + a[i]  , f[i][0]);
					f[i][1] = max(f[j][1] + a[i]  , f[i][1]);
				}
			}
			
			else
			{
				f[i][0] = max(f[i][0] , max(f[j][0] , f[j][1]));
				f[i][1] = max(f[i][1] , max(f[j][0] , f[j][1]));
			}
		}
	}
	for(int i = 1;i<=n;i++)
	{
		cout << f[i][0] << ' ' << f[i][1] << '\n';
	}
	cout << max(f[n][0] , f[n][1]) << '\n';
}

int main()
{
	freopen("color.in" , "r" ,stdin);
	freopen("color.out" , "w" , stdout);
	cin >> T;
	while(T--)
	{
		solve();
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
