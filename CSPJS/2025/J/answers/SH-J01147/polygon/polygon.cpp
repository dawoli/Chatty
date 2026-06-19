#include <bits/stdc++.h>
using namespace std;
int n,ans;
int a[5005];
void f(int x,int y,int s)
{
	if (x==y)
	{
		ans++;
		return;
	}
	if (s>a[y]*2) f(x+1,y,s);
	if (s-a[x]>a[y]*2) f(x+1,y,s);
	return;
}
int main()
{
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for (int i=3;i<=n;i++)
	{
		int s=0;
		for (int j=1;j<=i;j++)
		{
			s+=a[j];
		}
		f(1,i,s);
	}
	cout << ans;
	return 0;
}
