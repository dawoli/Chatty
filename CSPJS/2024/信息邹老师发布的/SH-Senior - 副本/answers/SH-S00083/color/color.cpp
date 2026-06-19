#include<bits/stdc++.h>
using namespace std;
int a[100001],n,T,ans;
bool t[100001];
inline int read()
{
	int x=0,f=1;
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
int check()
{
	int cnt=0;
	int l=-1;
	for(int i=1;i<=n;i++)
	{
		if(!t[i])
		{
			if(l!=-1)
			{
				if(a[i]==a[l]) cnt+=a[i];
			}
			l=i;
		}
	}
	l=-1;
	for(int i=1;i<=n;i++)
	{
		if(t[i])
		{
			if(l!=-1)
			{
				if(a[i]==a[l]) cnt+=a[i];
			}
			l=i;
		}
	}
	return cnt;
}
void solve(int p)
{
	if(p>=n+1)
	{
		ans=max(ans,check());
		return ;
	}
	t[p]=0;
	solve(p+1);
	t[p]=1;
	solve(p+1);
	return ;
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	/*q.push(1);
	q.push(2);
	while(!q.empty())
	{
		cout<<q.top()<<" ";
		q.pop();
	}*/
	T=read();
	while(T--)
	{
		memset(t,0,sizeof(t));
		ans=0;
		n=read();
		for(int i=1;i<=n;i++) a[i]=read();
		solve(1);
		cout<<ans<<endl;
	}
	return 0;
}
