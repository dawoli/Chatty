#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10005;
int n,t,a[4][MAXN],sum1,sum2,sum3,cnt1,cnt2,cnt3;

int max3(int a,int b,int c)
{
	if(c > max(a,b))
	{
		return c;
	}
	if(b > max(a,c))
	{
		return b;
	}
	if(a > max(b,c))
	{
		return a;
	}
	return a;
}

void f(){
	for(int i = 0;i < n;i++)
	{
		if(max3(a[0][i],a[1][i],a[2][i]) == a[0][i] && cnt1 < n / 2)
		{
			sum1 += a[0][i];
			cnt1++;
		}
		if(max3(a[0][i],a[1][i],a[2][i]) == a[1][i] && cnt2 < n / 2)
		{
			sum2 += a[1][i];
			cnt2++;
		}
		if(max3(a[0][i],a[1][i],a[2][i]) == a[2][i] && cnt3 < n / 2)
		{
			sum3 += a[2][i];
			cnt3++;
		}
	}
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int i = 0;i < t;i++)
	{
		cin >> n;
		for(int j = 0;j < n;j++)
		{
			for(int k = 0;k < 3;k++)
			{
				cin >> a[k][j];
			}
		}
		f();
		cout << sum1+sum2+sum3 << endl;
	}
}
