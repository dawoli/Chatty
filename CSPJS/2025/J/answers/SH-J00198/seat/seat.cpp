#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int a[105];

bool cmp(int x,int y)
{
	return x > y;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	swap(n,m);
	for(int i = 1;i <= n * m;i++) cin >> a[i];
	int sc = a[1],pos = -1;
	sort(a + 1,a + n * m + 1,cmp);
	for(int i = 1;i <= n * m;i++)
	{
		if(a[i] == sc)
		{
			pos = i;
			break;
		}
	}
	for(int i = 1;i <= n;i++)
	{
		if(i & 1)
		{
			for(int j = 1;j <= m;j++)
			{
				pos--;
				if(pos == 0)
				{
					cout << i << " " << j;
					return 0;
				}
			}
		}
		else
		{
			for(int j = m;j >= 1;j--)
			{
				pos--;
				if(pos == 0)
				{
					cout << i << " " << j;
					return 0;
				}
			}
		}
	}
	return 0;
}

// 庆历四年春，腾子京谪守巴陵郡。越明年，政通人和，百废俱兴，乃重修岳阳楼，增其旧制，刻唐贤今人诗赋于其上，属予作文以记之。
