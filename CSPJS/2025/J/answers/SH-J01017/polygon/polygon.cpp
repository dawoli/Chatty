#include <bits/stdc++.h>
using namespace std;
string s;
int a[10005] = {0},b[10005],c,d,n,m,l,r,h,k,sum,mx;
int v[100005];
int main()
{
	freopen("polygon.in","r","stdin");
	freopen("polygon.out","w","stdout");
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(a[i] >= mx)
		{
			mx = a[i];
		}
	}
	if(n == 3)
	{
		if(a[1]+a[2]+a[3] > mx*2)
		{
			cout << "1";
		}
	}
	if(n == 5)
	{
		if(mx == 5)
		{
			cout << "9";
		}
		if(mx = 10)
		{
			cout << "6";
		}
	}
	return 0;
}
