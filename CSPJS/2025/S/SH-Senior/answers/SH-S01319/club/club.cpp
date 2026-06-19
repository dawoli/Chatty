#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

int a[10005];
int b[10005];
int c[10005];
int q[105];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		if(n == 2)
		{
			cin >> a[1] >> b[1] >> c[1];
			cin >> a[2] >> b[2] >> c[2];
			q[1] = a[1] + b[2];
			q[2] = a[1] + c[2];
			q[3] = b[1] + a[2];
			q[4] = b[1] + c[2];
			q[5] = c[1] + b[2];
			q[6] = c[1] + a[2];
			int ans = -1;
			for(int i = 1;i <= 6;i++)
			{
				if(q[i] >= ans) ans = q[i];
			}
			
			cout << ans <<endl;
		}
		else
		{
			bool flag = 1;
			for(int i = 1;i <= n;i++)
			{
				cin >> a[i] >> b[i] >> c[i];
				if(b[i] != 0 || c[i] != 0) flag = 0;
			}
			if(flag)
			{
				for(int i = 1;i <= n;i++)
				{
					for(int j = 1;j <= n;j++)
					{
						if(a[j - 1] < a[j]) swap(a[j - 1] , a[j]);
					}
				}
				int sum = 0;
				for(int i = 0;i < n / 2;i++)
				{
					sum += a[i];
					cout << a[i] <<endl;
				}
				cout << sum <<endl;
			}
		}
	}
	return 0;	
} 
