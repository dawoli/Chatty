#include<bits/stdc++.h>
using namespace std;
#define int long long
namespace IO
{
	char buf[1<<16],*p1,*p2,ibuf;
	#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,sizeof(buf),stdin)),p1==p2?EOF:*p1++)
	int rd(int x=0,int f=1)
	{
		for(;!isdigit(ibuf);ibuf=getchar())if(ibuf=='-')f=-1;
		for(;isdigit(ibuf);ibuf=getchar())x=x*10+(ibuf^48);
			return x*f;
	}
	int rds(char*s,int n=0)
	{
		for(;!isgraph(ibuf);ibuf=getchar());
		for(;isgraph(ibuf);ibuf=getchar())s[n++]=ibuf;
			return s[n]=0,n;
	}
}
using IO::rd;using IO::rds;
int c[505][505];
int a[505][505];
int js[505];
int inv[505];
int cnt[505];
int sum[505];
const int mod=998244353;
char s[505];
int dp[2][505][505];
void add(int&x,int y)
{
	x=(x+y)%mod;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n=rd(),m=rd();
	rds(s+1);
	for(int i=1;i<=n;i++)cnt[rd()]++;
	sum[0]=cnt[0];
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+cnt[i];
	js[0]=inv[0]=inv[1]=1;
	for(int i=1;i<=n;i++)js[i]=js[i-1]*i%mod;
	for(int i=2;i<=n;i++)inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	for(int i=1;i<=n;i++)inv[i]=inv[i-1]*inv[i]%mod;
	for(int i=0;i<=n;i++)for(int j=0;j<=i;j++)c[i][j]=js[i]*inv[i-j]%mod*inv[j]%mod;
	for(int i=0;i<=n;i++)for(int j=0;j<=i;j++)a[i][j]=js[i]*inv[i-j]%mod;
	auto f=dp[0],g=dp[1];
	f[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		swap(f,g);
		for(int j=0;j<=i+1;j++)for(int k=0;k<=i+1;k++)f[j][k]=0;
		for(int j=0;j<i;j++)
		{
			int x=cnt[j+1];
			int L=sum[j],R=n-sum[j];
			// L already gone, R trying
			// x guys will leave if i gone
			int lbd=max((int)0,i-1-R);
			int _bd=min(L,i-1);
			for(int l=lbd;l<=_bd;l++)// l left guys were tested
			{
				int r=i-1-l;
				//left
				int _bd=min(x,r);
				int X=g[j][l]*(L-l)%mod;
				for(int k=0;k<=_bd;k++)add(f[j+1][l+1+k],X*c[r][k]%mod*a[x][k]);
				X=g[j][l];
				_bd=min(x,r+1);
				// cout<<"_BD: "<<j<<' '<<l<<' '<<_bd<<' '<<r+1<<' '<<x<<' '<<X<<' '<<c[r+1][1]<<' '<<a[x][1]<<endl;
				if(s[i]=='0')for(int k=0;k<=_bd;k++)add(f[j+1][l+k],X*c[r+1][k]%mod*a[x][k]);
				else add(f[j][l],X);
			}
		}
		// for(int j=0;j<=i;j++,cout<<endl)for(int k=0;k<=i;k++)cout<<f[j][k]<<' ';
			// cout<<endl;
	}
	int ans=0;
	for(int j=0;j<=n-m;j++)
	{
		int L=sum[j],R=n-sum[j];
		add(ans,f[j][L]*js[R]);
	}
	printf("%lld\n",ans);
}