#include<bits/stdc++.h>
using namespace std;

int m,n;
int scoresss[102];
int rs;
int x,y;
int d;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++)cin>>scoresss[i];
	rs = scoresss[1];
	sort(scoresss+1,scoresss+n*m+1);
	x = 1;
	y = 1;
	d = 1;
	for(int i = n*m;i>=1;i--)
	{
		if(scoresss[i] == rs)
		{
			cout<<x<<' '<<y;
			return 0;
		}
		if(y+d<=n && y+d>=1)y+=d;
		else
		{
			x++;
			d = d*-1;
		}
	}
	return 0;
}
