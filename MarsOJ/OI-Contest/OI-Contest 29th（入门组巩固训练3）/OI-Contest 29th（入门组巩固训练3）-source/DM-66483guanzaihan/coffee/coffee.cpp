#include <bits/stdc++.h>
using namespace std;
int a[8];
int main()
{
	freopen("coffee.in","r",stdin);
	freopen("coffee.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int T, n, m,sum=0;
	string s;
	cin >> T;
	for(int i = 1;i <= T;i++)
	{
		memset(a,0,sizeof(a));
		for(int j = 1;j <= 5;j++)
		{
			for(int k = 1;k <= 8;k++)
			{
				cin >> s;
				if(s=="math")
					a[j]++;
			}
		}
		sum = a[1]+a[2]+a[3]+a[4]+a[5];
		cin >> n >> m;
		int ans = n/7*sum;
		if(n%7!=0)
		{
			int t = n%7,b=(m+1>7 ? (m+1)%7 : m+1);
			while(t>0)
			{
				if(b>7) b%=7;
				ans+=a[b];
				t--;
				b++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
