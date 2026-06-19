#include<bits/stdc++.h>
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
	const int N=20,M=(1<<18);
	int dp[N][N][M];
	bool f[N][N][M];
	int main()
	{
		printf("512MB=536870912\n");
		printf("use %lld",sizeof(dp)+sizeof(f));
		return 0;
	}
}
signed main()
{
	//ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz
	//1234567890-=[]{};:'"',./?><~`!@#$%^&*()1234567890.+-*/\|
	//freopen(".in","r",stdin);
	freopen("memory.out","w",stdout);
	SH_S00929huletian::main();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

