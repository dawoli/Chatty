#include <bits/stdc++.h>
using namespace std;
bool checknext(int nn,int nm,int n,int m)
{
	if(nn==0|| nm==0||nn>m||nm>m||map[n][m]=false) return false;
	return true;
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","r",stdout);
	int T,n,m,k,sn,sm,sk;
	bool map[1005][1005],been[1005][1005],cnt=0;
	int adn[4]={0,-1,0,1};
	int adm[4]={1,0,-1,0};
	cin >> T;
	for(int i=1;i<=T;i++)
	{
		memset(map,0,sizeof(map));
		memset(been,0,sizeof(been));
		cin >>n>>m>>k;
		cin >>sn>>sm>>sk;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				char c;
				cin >> c;
				if(c=='.')
				{
					map[i][j]=true;
				}
				else
				{
					map[i][j]=false;
				}
			}
		}
		been[sn][sm]=true;
		cnt=1;
		for(int i=1;i<=k;i++)
		{
			if(checknext(n+adn[sk],m+adm[sk],n,m))
			{
				n+=adn[sk];
				m+=adn[sk];
				been[n][m]=true;
			}
			else
			{
				sk=(sk+1)%4;	
			} 
		}
		for(int i=1;i<=1005;i++)
		{
			for(int j=1;j<=1005;j++)
			{
				if(been[i][j])	
				{
					cnt++;
				}
			}
		}
		cout << cnt;
		return 0;
	}
}
