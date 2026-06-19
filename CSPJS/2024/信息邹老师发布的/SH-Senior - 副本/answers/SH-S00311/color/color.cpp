//65
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2005;
int a[N],n;
void cmx(int &a,int b){if(a<b)a=b;}

namespace s100{
	int f[105][105][105];	
	void solve()
	{
		int x;
			for(int i=0;i<=100;i++)
				for(int j=0;j<=100;j++)
					for(int k=0;k<=100;k++)
						f[i][j][k]=-0x3f3f3f3f;
			f[0][0][0]=0;	
			for(int i=1;i<=n;i++)
			{
				scanf("%d",&x);
				for(int j=0;j<=100;j++)
					for(int k=0;k<=100;k++)
					{
						cmx(f[i][x][k],f[i-1][j][k]+(j==x?x:0));//a red
						cmx(f[i][j][x],f[i-1][j][k]+(k==x?x:0));
					}
			}
			int ans=0;
			for(int j=1;j<=100;j++)
				for(int k=1;k<=100;k++)
					cmx(ans,f[n][j][k]);
			printf("%d\n",ans);
	}
}
namespace s_a_small{
	int f[2000005][12][12];	
	void solve()
	{
		int x;
			for(int i=0;i<=n;i++)
				for(int j=0;j<=10;j++)
					for(int k=0;k<=10;k++)
						f[i][j][k]=-0x3f3f3f3f;
			f[0][0][0]=0;	
			for(int i=1;i<=n;i++)
			{
				scanf("%d",&x);
				for(int j=0;j<=10;j++)
					for(int k=0;k<=10;k++)
					{
						cmx(f[i][x][k],f[i-1][j][k]+(j==x?x:0));//a red
						cmx(f[i][j][x],f[i-1][j][k]+(k==x?x:0));
					}
			}
			int ans=0;
			for(int j=1;j<=10;j++)
				for(int k=1;k<=10;k++)
					cmx(ans,f[n][j][k]);
			printf("%d\n",ans);
	}
}
namespace s2000{
	int f[2005][2005];
	
	void solve(){
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				f[i][j]=-0x3f3f3f3f;
		for(int i=0;i<=n;i++) f[i][0]=f[0][i]=0;	
		for(int i=1;i<=n;i++) scanf("%d",&a[i]); 
		a[0]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=i-2;j++) cmx(f[i][j],f[i-1][j]+(a[i]==a[i-1]?a[i]:0));
			for(int j=0;j<=i-2;j++) cmx(f[i][i-1],f[j][i-1]+(a[i]==a[j]?a[i]:0));
			for(int j=0;j<=i-2;j++) cmx(f[j][i],f[j][i-1]+(a[i]==a[i-1]?a[i]:0));
			for(int j=0;j<=i-2;j++) cmx(f[i-1][i],f[i-1][j]+(a[i]==a[j]?a[i]:0));
		}
//		for(int i=0;i<=n;i++){for(int j=0;j<=n;j++) printf("%d ",f[i][j]); printf("\n");}
			int ans=0;
			for(int j=0;j<=n;j++)
				for(int k=0;k<=n;k++)
					cmx(ans,f[j][k]);
			printf("%d\n",ans);
	} 
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int qwq;
	scanf("%d",&qwq);
	while(qwq--)
	{
		scanf("%d",&n);
		if(n<=100) s100::solve();
		else if(n<=2000) s2000::solve();  
		else s_a_small::solve();
	}
	return 0;
}

