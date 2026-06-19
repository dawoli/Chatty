#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<48||ch>57) {if(ch=='-') f=-1;ch=getchar();}
	while(ch>=48&&ch<=57) x=x*10+ch-48,ch=getchar();
	return x*f;
}
int n,a[100005];
int ans,t[100005];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i) a[i]=read(),++t[a[i]];
	for(int i=0;i<=100000;++i)
	{
		ans=max(0,ans-t[i]);
		ans+=t[i];
	}
	cout<<ans<<"\n";
	return 0;
}

