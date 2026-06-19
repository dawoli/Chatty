#include <bits/stdc++.h>
using namespace std;
int t,d;
string s;
long long n,m,k,x,y;
char a[1005][1005],b[1005][1005];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> t;
	for(int i=1;i<=t;i++)
	{
		cin >> n >> m >> k >> x >> y >> d;
		for(int l=1;l<=n;l++)
		{
			cin >> s;
			for(int j=1;j<=m;j++)
			{
				a[l][j]=s[j-1];
				b[l][j]='0';
			}
		}
		b[x][y]='1';
		for(int j=1;j<=k;j++)
		{
			if(d==0 && a[x][y+1]=='.' && y+1<=m)
			{
				y+=1;
				b[x][y]='1';
				continue;
			}
			if(d==1 && a[x+1][y]=='.' && x+1<=n)
			{
				x+=1;
				b[x][y]='1';
				continue;
			}
			if(d==2 && a[x][y-1]=='.' && y-1>=1)
			{
				y-=1;
				b[x][y]='1';
				continue;
			}
			if(d==3 && a[x-1][y]=='.' && x-1>=1)
			{
				x-=1;
				b[x][y]='1';
				continue;
			}
			d=(d+1)%4;
		}
		long long sum=0;
		for(int l=1;l<=n;l++)
			for(int j=1;j<=m;j++)
				if(b[l][j]=='1')
					sum++;
		cout << sum << '\n';
	}
	return 0;
}
