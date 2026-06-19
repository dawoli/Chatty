#include<bits/stdc++.h>
using namespace std;
long long a[100005];
long long b[100005];//·ÀÓù
long long c[100005];//½ø¹¥
inline long long read()
{
	long long x=0,f=1;
	char ch;
	ch=getchar();
	while(ch>'9'||ch<'0')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
void write(long long x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	long long n,x,ans=0;
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	stable_sort(a+1,a+n+1);
	int cnt=a[1];
	int j=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==cnt)
		{
			b[j]++;
			c[j]++;
		}
		else
		{
			cnt=a[i];
			j++;
			b[j]++;
			c[j]++;
		}
	}
	int flag=0;
	for(int i=1;i<=j;i++)
	{
		for(int k=i+1;k<=j;k++)
		{
			if(c[k]>=b[i])
			{
				b[i]=0;
				c[k]-=b[i];
				break;
			}
			else
			{
				b[i]-=c[k];
				c[k]=0;
			}
			if(c[j]==0)
			{
				flag=1;
				break;
			}
		}
		if(flag) break;
	}
	for(int i=1;i<=n;i++)
	{
		ans+=b[i];
	}
	write(ans);
	return 0;
}
