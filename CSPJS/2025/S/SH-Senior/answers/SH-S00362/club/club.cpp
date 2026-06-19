#include<bits/stdc++.h>
#define MAXN 100010
using namespace std;

long long t,n,ans,hn,i,j,k,a[MAXN][4],S1,S2,S3,f[510][510][510];
long long F(long long i,long long j,long long k)
{
	if(i < 0||j < 0||k < 0)return 0;
	return f[i][j][k];
}
bool cmp(int x,int y){return x>y;}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		hn = n/2;
		ans = 0;
		S1 = S2 = S3 = 0;
		for(i = 1;i <= n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			S1 += a[i][1],S2 += a[i][2],S3 += a[i][3];
		}
		if((S1 == 0 && S2 == 0)||(S2 == 0 && S3 == 0)||(S1 == 0 && S3 == 0))
		{
			long long tmp[MAXN];
			if(S1 != 0)for(i = 1;i <= n;i++)tmp[i] = a[i][1];
			else if(S2 != 0)for(i = 1;i <= n;i++)tmp[i] = a[i][2];
			else if(S3 != 0)for(i = 1;i <= n;i++)tmp[i] = a[i][3];
			else
			{
				cout<<0<<'\n';
				continue;
			}
			sort(tmp+1,tmp+n+1,cmp);
			for(i = 1;i <= hn;i++)ans += tmp[i];
			cout<<ans<<'\n';
			continue;
		}
		if(n <= 500)
		{
			f[1][0][0] = a[1][1],f[0][1][0] = a[1][2],f[0][0][1] = a[1][3];
			for(i = 2;i <= n;i++)
			{
				for(j = 0;j <= min(i,hn);j++)
				{
					for(k = 0;k <= min(i-j,hn);k++)
					{
						f[j][k][i-j-k] = max(F(j-1,k,i-j-k)+a[i][1],max(F(j,k-1,i-j-k)+a[i][2],F(j,k,i-j-k-1)+a[i][3]));
					}
				}
			}
			for(i = 0;i <= hn;i++)
			{
				for(j = 0;j <= hn;j++)
				{
					if(n-i-j <= hn)ans = max(ans,f[i][j][n-i-j]);
				}
			}
			cout<<ans<<'\n';
			continue;
		}
		cout<<0<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
