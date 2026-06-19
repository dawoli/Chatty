#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
struct node
{
	long long x,y,z;
} p[200005];
long long a[200005],b[200005],c[200005];
int n;
int cur1=0,cur2=0,cur3=0;
long long ans=0;
int T;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--) {
		cur1=0,cur2=0,cur3=0;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>p[i].x>>p[i].y>>p[i].z;
			if(p[i].x>=p[i].y&&p[i].x>=p[i].z)	
			{
				a[++cur1]=max(p[i].y,p[i].z)-p[i].x;
				ans+=p[i].x;
			}
			else if(p[i].y>=p[i].x&&p[i].y>=p[i].z)
			{
				b[++cur2]=max(p[i].x,p[i].z)-p[i].y;
				ans+=p[i].y;
			}
			else
			{
				c[++cur3]=max(p[i].x,p[i].y)-p[i].z;
				ans+=p[i].z;
			}
		}	
		if(cur1>n/2)
		{
			sort(a+1,a+cur1+1,cmp);
			for(int i=1;i<=cur1-n/2;i++)
			{
				ans+=a[i];
			}
		}
		if(cur2>n/2)
		{
			sort(b+1,b+cur2+1,cmp);
			for(int i=1;i<=cur2-n/2;i++)
			{
				ans+=b[i];
			}
		}
		if(cur3>n/2)
		{
			sort(c+1,c+cur3+1,cmp);
			for(int i=1;i<=cur3-n/2;i++)
			{
				ans+=c[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
