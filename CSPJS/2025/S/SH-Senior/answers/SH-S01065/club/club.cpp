#include <bits/stdc++.h>
using namespace std;
long long t,n,ans;
struct num
{
	long long a,b,c;
}a[100005];
bool cmp(num x,num y)
{
	return max(max(x.a,x.b),x.c)>=max(max(y.a,y.b),y.c);
}
bool acmp(num x,num y)
{
	return min(x.a-x.b,x.a-x.c)>=min(y.a-y.b,y.a-y.c);
}
bool bcmp(num x,num y)
{
	return min(x.b-x.a,x.b-x.c)>=min(y.b-y.a,y.b-y.c);
}
bool ccmp(num x,num y)
{
	return min(x.c-x.b,x.c-x.a)>=min(y.c-y.b,y.c-y.a);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		vector<num> v1,v2,v3;
		ans=0;
		cin>>n;
		for (int j=1;j<=n;j++)
			scanf("%d %d %d\n",&a[j].a,&a[j].b,&a[j].c);
	 	sort(a+1,a+n+1,cmp);
	 	for (int j=1;j<=n;j++)
	 	{
	 		if (a[j].a>=a[j].b&&a[j].a>=a[j].c)
	 		{
	 			v1.push_back(a[j]);
	 			ans+=a[j].a;
			 }
			else if (a[j].b>=a[j].c&&a[j].b>=a[j].a)
	 		{
	 			v2.push_back(a[j]);
	 			ans+=a[j].b;
			 }
			else
			{
				v3.push_back(a[j]);
				ans+=a[j].c;
			}
		 }
		if (v1.size()>(n/2))
		{
			sort(v1.begin(),v1.end(),acmp);
			for (int j=v1.size()-1;j>=n/2;j--)
			{
				ans-=v1[j].a;
				if (v1[j].b>=v1[j].c)
					ans+=v1[j].b;
				else
					ans+=v1[j].c;
			}
		}
		else if (v2.size()>(n/2))
		{
			sort(v2.begin(),v2.end(),bcmp);
			for (int j=v2.size()-1;j>=n/2;j--)
			{
				ans-=v2[j].b;
				if (v2[j].a>=v2[j].c)
					ans+=v2[j].a;
				else
					ans+=v2[j].c;
			}
		}
		else if (v3.size()>(n/2))
		{
			sort(v3.begin(),v3.end(),ccmp);
			for (int j=v3.size()-1;j>=n/2;j--)
			{
				ans-=v3[j].c;
				if (v3[j].b>=v3[j].a)
					ans+=v3[j].b;
				else
					ans+=v3[j].a;
			}
		}
		cout<<ans<<endl;
	}
 } 
