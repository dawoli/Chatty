#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a > b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	vector<int> a(m*n+1,0);
	for(int i = 1;i <= n*m;i++)
	{
		cin >> a[i];
	}
	int R = a[1];
	sort(a.begin()+1,a.end(),cmp);
	int c = 1,r = 1;
	bool jo = 0;
	if(R == a[1])
	{
		cout << c << ' ' << r;
		return 0;
	}
	int cnt  = 0;
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			cnt++;
			if(a[cnt]== R)
			{
				cout << r << ' ' << c;
				return 0;
			}
			if(!jo)
			{
				if(c+1 > n)
				{
					r++;
					jo = 1;
				}
				else
				{
					c++;
				}
			}
			else
			{
				if(c-1 < 1)
				{
					r++;
					jo = 0;
				}
				else
				{
					c--;
				}
			}
		}
	}
	return 0;
}
