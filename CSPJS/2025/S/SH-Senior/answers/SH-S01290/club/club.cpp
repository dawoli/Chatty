#include<bits/stdc++.h>
using namespace std;
struct node
{
	int a,b,c;
};
node a[200005];
//node dp[5][200005];
bool cmp1(node x,node y)
{
	return x.a>y.a; 
}
bool cmp2(node x,node y)
{
	return x.b>y.b; 
}
bool cmp3(node x,node y)
{
	return x.c>y.c; 
}
int main()
{
	freopen("club5.in","r",stdin);
	freopen("club5.out","w",stdout);
	int t,n,ans=-1;
	cin>>t;
	while(t--)
	{	
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].a>>a[i].b>>a[i].c;
		}
		int num=0;
		//aÕ¼Âún/2 
		sort(a+1,a+n+1,cmp1);
		for(int j=1;j<=n/2;j++)
		{
			num+=a[j].a;
		}
		for(int j=(n/2)+1;j<=n;j++)
		{
			num+=max(a[j].b,a[j].c);
		}
		ans=max(ans,num);
		num=0;
		//bÕ¼Âún/2
		sort(a+1,a+n+1,cmp2);
		for(int j=1;j<=n/2;j++)
		{
			num+=a[j].b;
		}
		for(int j=(n/2)+1;j<=n;j++)
		{
			num+=max(a[j].a,a[j].c);
		}
		ans=max(ans,num);
		num=0;
		//cÕ¼Âún/2 
		sort(a+1,a+n+1,cmp3);
		for(int j=1;j<=n/2;j++)
		{
			num+=a[j].a;
		}
		for(int j=(n/2)+1;j<=n;j++)
		{
			num+=max(a[j].b,a[j].c);
		}
		ans=max(ans,num);
		num=0;
		cout<<ans<<"\n";
		ans=-1;
	}
	return 0;
}
