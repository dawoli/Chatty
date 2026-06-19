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
inline void main_init()
{
	string FILENAME="duel";
	if(FILENAME!="")
	{
		freopen((FILENAME+".in").c_str(),"r",stdin);
		freopen((FILENAME+".out").c_str(),"w",stdout);
	}else puts("Warning: No file IO.");
	ios::sync_with_stdio(0),cin.tie(),cout.tie();
}
int n,a[100009],ans,nw=1;
inline void main_solve()
{
	n=read<int>();
	for(int i=1;i<=n;++i)a[i]=read<int>();
	sort(a+1,a+n+1);
	ans=n;
	for(int i=1;i<=n;++i)
		if(i>nw&&a[i]>a[nw])
		{
			--ans;
			++nw;
		}
	printf("%d",ans);	
}
int main()
{
	main_init();
	main_solve();
	return 0;
}

