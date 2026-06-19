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
	const int N=1e6+1;
	int main()
	{
		int v1,v2;
		char file[N]=__FILE__;
		int len=strlen(file);
		string s;
		for(int i=21;i<len&&file[i]!='\\'&&file[i]!='/';++i) s+=file[i];
		string iout=s+".out",ians=s+".ans";
		ifstream out(iout),ans(ians);
		while(out>>v1){
			ans>>v2;
			if(v1!=v2){
				printf("WA output %lld expect %lld",v1,v2);
				return 0;//D:\SH-S00929huletian\//
			}
		}
		printf("AC");
		return 0;
	}
}
signed main()
{
	//ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz
	//1234567890-=[]{};:'"',./?><~`!@#$%^&*()1234567890.+-*/\|
	//freopen(".in","r",stdin);
	freopen("result.out","w",stdout);
	SH_S00929huletian::main();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

