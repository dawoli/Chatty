#include<bits/stdc++.h>
typedef long long LL;
#define int LL
using namespace std;
namespace SH_S00929huletian
{
	//试题解压密码：Ren5Jie4Di4Ling5%
	//我的名字：胡乐天
	//我的准考证号：SH-S00929 
	//文件夹名：SH-S00929huletian
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
	//employ employer employee
	//我要拿下今年CSP-S复赛一等奖 
	//我不要爆零！！！我不要爆零！！！我不要爆零！！！我不要爆零！！！我不要爆零！！！
	//不爆零！！！不爆零！！！不爆零！！！不爆零！！！不爆零！！！
	//爆零警告 
	//s[i]=0则拒绝，s[i]=1则录用 
	const int N=5e2+1,MOD=998244353;
	int n,m,ans=0,s[N],c[N],id[N];
	inline bool check()
	{
		for(int i=1;i<=n;++i)
			if(s[i]==0) return false;
		return true;
	}
	inline bool check2()
	{
		for(int i=1;i<=n;++i)
			if(s[i]==1) return false;
		return true;
	}
	inline int factorial(int n)
	{
		if(n==0) return 1;
		return factorial(n-1)*n%MOD;
	}
	int main()
	{
		n=read();m=read();
		for(int i=1;i<=n;++i) s[i]=read();
		for(int i=1;i<=n;++i) c[i]=read();
		if(check()){//s为全1 
			write(factorial(n));
			return 0;
		}
		if(check2()){//s为全0 
			putchar('0');
			return 0;
		}
		if(m==n&&!check()){//m=n且s不为全1 
			putchar('0');
			return 0;
		}
		for(int i=1;i<=n;++i) id[i]=i;
		do{
			int people=0;//被录用的人数：people 
			for(int i=1;i<=n;++i){
				//未录用的人数：i-people-1 
				if(i-people-1<c[i]&&s[i]) ++people;
			}
			if(people>=m) ans=(ans+1)%MOD;
		}while(next_permutation(id+1,id+n+1));//#include<bits/stl_algo.h>
		write(ans);
		return 0;
	}
}
signed main()
{
	//ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz
	//1234567890-=[]{};:'"',./?><~`!@#$%^&*()1234567890.+-*/\|
	//https://www.mozilla.org/zh-CN/privacy/firefox/
	//https://hao.360.com/?src=lm&ls=n039d848e98 
	//IT DIY VIP ASAP PRC CPC WTO WHO
	//FAQ STEM TV APP
	//teamwork band DJ(=disc jockey) lead
	//off-stage backstage
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	SH_S00929huletian::main();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

