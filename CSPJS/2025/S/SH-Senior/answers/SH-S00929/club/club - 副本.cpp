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
		const int N=1e6+1;
		int n,ans=0,member[4],a[N][4];
		inline void dfs(int x,int satisfy)
		{
			if(x>n){
				ans=max(ans,satisfy);
				return;
			}
			for(int i=1;i<=3;++i){
				if(member[i]==n/2) continue;
				++member[i];
				dfs(x+1,satisfy+a[x][i]);
				--member[i];
			}
		}
		inline int get_answer()
		{
			ans=0;
			dfs(1,0);
			return ans;
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
	//ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz
	//1234567890-=[]{};:'"',./?><~`!@#$%^&*()1234567890.+-*/\|
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	SH_S00929huletian::main();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

