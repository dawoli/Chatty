#include<bits/stdc++.h>
typedef long long LL;
#define int LL
using namespace std;
namespace SH_S00929huletian
{
	//胡乐天 
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
	const int N=1e6+1;
	int n,q,length[N],len[N];
	string s[N][3],t[N][3];
	inline void input()
	{
		fast();
		cin>>n>>q;
		for(int i=1;i<=n;++i){
			cin>>s[i][1]>>s[i][2];
			length[i]=s[i][1].length();
		}
		for(int i=1;i<=q;++i){
			cin>>t[i][1]>>t[i][2];
			len[i]=t[i][1].length();
		}
	}
	inline int solve(string t1,string t2,int len)
	{
		int ans=0;
		auto check=[&](string s1,string s2,int length)
		{
			for(int i=0;i<len-length+1;++i){
				if(t1.substr(i,length)!=s1) continue;
				string t=t1;
				t=t.replace(i,length,s2);
				if(t==t2) return true;
			}
			return false;
		};
		for(int i=1;i<=n;++i)
			if(check(s[i][1],s[i][2],length[i])) ++ans;
		return ans;
	}
	int main()
	{
		input();
		for(int i=1;i<=q;++i){
			write(solve(t[i][1],t[i][2],len[i]));
			putchar('\n');
		}
		return 0;
	}
}
signed main()
{
	//ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz
	//1234567890-=[]{};:'"',./?><~`!@#$%^&*()1234567890.+-*/\|
	//qwertyuiopasdfghjklzxcvbnm
	//.in,.out
	//https://www.winrar.com.cn/download-70064scp.html
	//https://www.mozilla.org/zh-CN/firefox/all/desktop-esr/win64/zh-CN/
	//https://www.mozilla.org/en-US/firefox/132.0.2/system-requirements/
	//https://www.winrar.com.cn/download/winrar-x64-700scp.exe
	//我的电脑 此电脑 
	//不要爆零 
	//我想AC本题，不想爆零 
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	SH_S00929huletian::main();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

