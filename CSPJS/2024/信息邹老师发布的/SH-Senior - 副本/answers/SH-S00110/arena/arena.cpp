#include <bits/stdc++.h>
using namespace std;
template<typename TN> inline TN read()
{
	char ch=getchar();
	while(ch!='-'&&(ch<'0'||ch>'9'))ch=getchar();
	TN rst=0;
	bool mns=0;
	if(ch=='-')
	{
		mns=1;
		ch=getchar();
	}
	while('0'<=ch && ch<='9')
	{
		rst=(rst<<1)+(rst<<3)+ch-'0';
		ch=getchar();
	}
	return mns?-rst:rst;
}
inline bool __read()
{
	char ch=getchar();
	while(ch!='0'&&ch!='1')ch=getchar();
	return ch=='1';
}
inline void main_init()
{
	string FILENAME="arena";
	if(FILENAME!="")
	{
		freopen((FILENAME+".in").c_str(),"r",stdin);
		freopen((FILENAME+".out").c_str(),"w",stdout);
	}else puts("Warning: No file IO.\n");
	ios::sync_with_stdio(0),cin.tie(),cout.tie();
}
int T,n,np,m,K,a[100009],ap[100009],app[100009],c[100009];
vector<bool> d[29];
inline int solve()
{
	/*vector<int> nw;
	for(int i=1;i<=n;++i)nw.push_back(i);
	while(nw.size()!=1)
	{
		
	}*/
	return rand(); 
}
inline void main_solve()
{
	np=read<int>(),m=read<int>();
	for(int i=1;i<=np;++i)app[i]=read<int>();
	for(int i=1;i<=m;++i)c[i]=read<int>();
	while((1<<K)<np)++K;
	for(int i=1;i<=K;++i)
	{
		int cnt=1<<(K-i);
		while(cnt--)d[i].push_back(__read());
	}
	T=read<int>();
	while(T--)
	{
		array<int,4> X={read<int>(),read<int>(),read<int>(),read<int>()};
		for(int i=1;i<=np;++i)ap[i]=app[i]^X[i&3];
		int rst=0;
		for(int i=1;i<=m;++i)
		{
			n=c[i];
			for(int j=1;j<=n;++j)a[i]=ap[j];
			int k=0;
			while((1<<k)<n)++k;
			for(int j=n+1;j<=(1<<k);++j)a[j]=1e9;
			n=(1<<k);
			rst^=i*solve();
		}
		printf("%d",rst);
	}
}
int main()
{
	main_init();
	main_solve();
	return 0;
}

