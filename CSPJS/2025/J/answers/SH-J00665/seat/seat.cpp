#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 +5;
int a[N];
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
	cin >> a[1];
	int num = a[1];
	for(int i = 2;i <= n * m;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n * m + 1,cmp);
	int c,r,cnt;
	for(int i = 1;i <= n * m;i++)
	{
		if(a[i] == num)
		{
			cnt = i;
			break;
		}
	}
	c = cnt / n + (cnt % n != 0);
	if(c & 1)
	{
		if(cnt % n == 0)
			r = n;
		else
			r = cnt % n;
	}
	else
	{
		if(cnt % n == 0)
			r = 1;
		else
			r = n - cnt % n + 1;
	}
	cout << c << " " << r;
	return 0;
} 
