#include<bits/stdc++.h>
typedef long long LL;
#define int LL
using namespace std;
namespace SH_S00929huletian
{
	inline char get_char()
	{
		char c=getchar();
		while(c<=32&&c!=EOF) c=getchar();
		return c;
	}
	inline int read()
	{
		int x=0,f=1;
		char c=getchar();
		for(;c<'0'||c>'9';c=getchar()){if(c=='-') f=-1;if(c==EOF) return EOF;}
		for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
		return x*f;
	}
	inline void write(int x)
	{
		if(x<0) putchar('-'),x=-x;
		if(x>9) write(x/10);
		putchar(x%10+'0');
	}
	inline void fast()
	{
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);
	}
	int t;
	namespace SH_S00929huletianT1Club
	{
		const int N=1e6+1,M=101;
		int n,ans=0,member[4],a[N][4],dp[M][M][M];
		bool vis[M][M][M];
		inline int dfs(int m1,int m2,int m3)
		{
			int x=m1+m2+m3;
			if(x>n) return 0;
			int ans=0;
			if(m1!=n/2) ans=max(ans,dfs(m1+1,m2,m3)+a[x][1]);
			if(m2!=n/2) ans=max(ans,dfs(m1,m2+1,m3)+a[x][2]);
			if(m3!=n/2) ans=max(ans,dfs(m1,m2,m3+1)+a[x][3]);
			return ans;
		}
		inline int dfs2(int m1,int m2,int m3)
		{
			int &ans=dp[m1][m2][m3];
			if(vis[m1][m2][m3]) return ans;
			vis[m1][m2][m3]=true;
			int x=m1+m2+m3;
			if(x>n) return ans=0;
			ans=0;
			if(m1!=n/2) ans=max(ans,dfs2(m1+1,m2,m3)+a[x][1]);
			if(m2!=n/2) ans=max(ans,dfs2(m1,m2+1,m3)+a[x][2]);
			if(m3!=n/2) ans=max(ans,dfs2(m1,m2,m3+1)+a[x][3]);
			return ans;
		}
		inline int get_answer()
		{
			if(n<=200){
				for(int i=0;i<=n/2;++i)
					for(int j=0;j<=n/2;++j)
						for(int k=0;k<=n/2;++k) vis[i][j][k]=false;
				return dfs2(0,0,0);
			}
			return dfs(0,0,0);
		}
		inline void solve()
		{
			n=read();
			for(int i=1;i<=n;++i)
				for(int j=1;j<=3;++j) a[i][j]=read();
			write(get_answer());
			putchar('\n');
		}
	}
	int main()
	{
		t=read();
		for(int i=1;i<=t;++i) SH_S00929huletianT1Club::solve();
		return 0;
	}
}
signed main()
{
	//inborn unfamiliar grown-up continuous either ruin eyesight fantastic ant surprising
	//awake eagle cartoon movie never-ending annoying brain researcher rate result
	//magician recent trick voluntary crazy therefore wonder shake bark
	//ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz
	//1234567890-=[]{};:'"',./?><~`!@#$%^&*()1234567890.+-*/\|
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	SH_S00929huletian::main();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

