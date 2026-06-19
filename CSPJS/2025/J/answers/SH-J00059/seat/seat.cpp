#include<bits/stdc++.h>
using namespace std;
int n,m,ach,cnt=0;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			cnt++;
			cin >> a[cnt];
		}
	}
	ach=a[1];
	sort(a+1,a+cnt+1);
	int p=lower_bound(a+1,a+cnt+1,ach)-a;
	p=cnt+1-p;
	int ansx,ansy;
	ansy=ceil(p*1.0/n);
	p=p%n;
	if(p==0)p=n;
	if(ansy%2==1)ansx=p;
	else ansx=n+1-p;
	cout << ansy << " " << ansx;
	return 0;
}
