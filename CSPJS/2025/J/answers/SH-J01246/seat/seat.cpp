#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int a[N];
int n,m;
int tot;
int sc;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	tot = n * m; 
	for(int t = 1;t <= tot;t++)
	{
		cin >> a[t];
	}
	sc = a[1];
	sort(a + 1,a + tot + 1);
	reverse(a + 1,a + tot + 1);
	int pos = 1;
	for(int t = 1;t <= m;t++)
	{
		if(t % 2 == 1)
		{
			for(int i = 1;i <= n;i++)
			{
				if(a[pos] == sc)
				{
					cout << t << " " << i;
					return 0; 
				} 
				else
				{
					pos++;
				}
			}
		} 
		else
		{
			for(int i = n;i >= 1;i--)
			{
				if(a[pos] == sc)
				{
					cout << t << " " << i;
					return 0; 
				} 
				else
				{
					pos++;
				} 	
			}
		}
	}
	return 0;
 } 
