#include<bits/stdc++.h>
using namespace std;
#define int long long
namespace IO{
char ibuf;
int rd(int x=0)
{
	for(;!isdigit(ibuf);ibuf=getchar());
	for(;isdigit(ibuf);ibuf=getchar())x=(x<<1)+(x<<3)+(ibuf^48);
	return x;
}
}using IO::rd;//namespace IO
void chm(int&x,int y){x=max(x,y);}
namespace BF{
int a[110];
int f[110][110][110];
signed slv()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T=rd();while(T--){
	int n=rd();
	for(int i=1;i<=n;i++)a[i]=rd();
	memset(f,0xcf,sizeof(f));f[0][0][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=100;j++)
		{
			for(int k=0;k<=100;k++)
			{
				chm(f[i][a[i]][k],f[i-1][j][k]+(a[i]==j)*j);
				chm(f[i][j][a[i]],f[i-1][j][k]+(a[i]==k)*k);
			}
		}
	}
	int ma=0;for(int i=0;i<=100;i++)for(int j=0;j<=100;j++)ma=max(ma,f[n][i][j]);
	printf("%lld\n",ma);
	}//while(T--)
	return 0;
}
}//namespace BF
namespace On{
int a[200020];
int pre[1000100];
int las[1000100];
int f[200020];
signed slv()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T=rd();while(T--){
	int n=rd(),ans=0;
	for(int i=1;i<=n;i++)
	{
		a[i]=rd();
		if(a[i]==a[i-1])i--,n--,ans+=a[i];
		else pre[i]=las[a[i]],las[a[i]]=i;
	}
	for(int i=1;i<=n;i++)f[i]=max(f[i-1],pre[i]?f[pre[i]+1]+a[i]:0);
	printf("%lld\n",f[n]+ans);
	for(int i=1;i<=n;i++)las[a[i]]=0;
	}//while(T--)
	return 0;
}
}//namespace On
using On::slv;
signed main(){return slv();}