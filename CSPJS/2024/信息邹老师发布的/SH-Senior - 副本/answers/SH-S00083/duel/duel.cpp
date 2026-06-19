#include<bits/stdc++.h>
using namespace std;
long long n,r[100001],a[100001],p=0,eat=1,cnt=0;
inline long long read()
{
	long long x=0,f=1;
	char ch;
	ch=getchar();
	while(ch<'0' || ch>'9') 
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) r[i]=read();
	sort(r+1,r+n+1);
	for(int i=1;i<=n;i++)
	{
		if(r[i]!=r[i-1])
		{
			a[++p]=1;
		}
		else a[p]++;
	}
	for(int i=2;i<=p;i++)
	{
		cnt=0;
		while(eat<i && cnt+a[eat]<=a[i])
		{
			cnt+=a[eat];
			a[eat]=0;
			eat++;
		}
		if(eat!=i)
		{
			a[eat]-=(a[i]-cnt);
		}
	}
	long long ans=0;
	for(int i=1;i<=p;i++) ans+=a[i];
	cout<<ans<<endl;
	return 0;
}
