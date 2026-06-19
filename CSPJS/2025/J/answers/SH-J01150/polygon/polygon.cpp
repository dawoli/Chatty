# include <bits/stdc++.h>//ÕâÌâÊ«ÈË£¿£¿£¿ 
using namespace std;
int n;
int a[5005]={0};
int b[5005]={0};
bool vis[5005]={0};
int ans=0;
int res=0;
void f(int x,int y,int cnt,int num,int a,int bb)
{
	a+=b[x];
	if(cnt==num)
	{
		if(a>bb)
		{
			ans++;
		}
		return;
	}
	for(int i=1;i<=y;i++)
	{
		if(vis[i]==0)
		{
			vis[i]=1;
			f(i,y,cnt+1,num,a,bb);
			vis[i]=0;
		}
	}
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","r",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n-1);
	for(int i=3;i<=n;i++)
	{
		memset(b,0,i+1);
		for(int j=1;j<=i;j++)
		{
			vis[j]=false;
			b[j]=a[j];
		}
		for(int num=2;num<=i-1;num++)
		{
			f(0,i-1,0,num,0,a[i]);
			for(int j=1;j<=num;j++)
			{
				ans/=j;
			}
			res+=ans;
			ans=0;
		}
	}
	cout<<res;
	return 0;
}
