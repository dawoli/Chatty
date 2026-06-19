#include <bits/stdc++.h> 
#include <cmath>
using namespace std;
int a[10005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,minn = 10005,minm = 10005;
	cin >> n >> m >> k;
	for(int i = 1;i <= n;i++)
	{
		int a,b,c;
		cin >> a >> b >> c; 
		minn = min(minn,c);
	}
	for(int i = 1;i <= n+1;i++)
	{
		cin >> a[i];
		minm = min(minm,a[1]);
	} 
	cout << minn+minm;
	return 0;
}
