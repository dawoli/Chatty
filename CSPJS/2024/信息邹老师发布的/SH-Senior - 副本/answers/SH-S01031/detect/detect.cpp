#include<bits/stdc++.h>
using namespace std;
int t,n,m,l,v;
int read()
{
	int x=0,f=1;char ch;
	ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	t=read();
	for(int i=1;i<=t;i++)
	{
		int ans=0;
		int aa,bb,cc;
		n=read();m=read();l=read();v=read();
		for(int j=1;j<=n;j++)
		{
			aa=read();bb=read();cc=read();
			if(bb>v) ans++;
		}
		cout<<ans<<" "<<m-1<<endl;
	}
	return 0;
} 
