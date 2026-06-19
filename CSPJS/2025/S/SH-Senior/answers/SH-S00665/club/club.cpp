#include<bits/stdc++.h>
using namespace std;
int t,n;
struct node
{
	int f1,f2,f3,minn;
}a[100005];
bool cmp(node x,node y)
{
	return x.minn<y.minn;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		int max1=0,max2=0,max3=0,maxn,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].f1>>a[i].f2>>a[i].f3;
			if(a[i].f1>a[i].f2&&a[i].f1>a[i].f3)max1++;
			if(a[i].f2>a[i].f1&&a[i].f2>a[i].f3)max2++;
			if(a[i].f3>a[i].f2&&a[i].f3>a[i].f1)max3++;
		}
		maxn=max(max1,max(max2,max3));
		if(maxn==max1)
		{
			for(int i=1;i<=n;i++)
			{
				ans+=a[i].f1;
				a[i].minn=min(a[i].f1-a[i].f2,a[i].f1-a[i].f3);
			}
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++)
			{
				ans-=a[i].minn;
			}
		}
		else if(maxn==max2)
		{
			for(int i=1;i<=n;i++)
			{
				ans+=a[i].f2;
				a[i].minn=min(a[i].f2-a[i].f1,a[i].f2-a[i].f3);
			}
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++)
			{
				ans-=a[i].minn;
			}
		}
		else if(maxn==max3)
		{
			for(int i=1;i<=n;i++)
			{
				ans+=a[i].f3;
				a[i].minn=min(a[i].f3-a[i].f2,a[i].f3-a[i].f1);
			}
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++)
			{
				ans-=a[i].minn;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
