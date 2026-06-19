#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e5+10;
struct node
{
	ll x,y,z;
	ll dis1,dis2;
}a[maxn];
ll b[maxn],c[maxn],d[maxn],btop,ctop,dtop;
bool cmp(node a,node b)
{
	if(a.dis1>b.dis1)return true;
	else if(a.dis1<b.dis1)return false;
	else return a.dis2>b.dis2;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll t;
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d));
		ctop=0;
		btop=0;
		dtop=0;
		ll n,k;
		cin>>n;
		k=n/2;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z&&a[i].y>=a[i].z)
			{
				a[i].dis1=a[i].x-a[i].y;
				a[i].dis2=a[i].y-a[i].z;
			}
			else if(a[i].x>=a[i].y&&a[i].x>=a[i].z&&a[i].z>=a[i].y)
			{
				a[i].dis1=a[i].x-a[i].z;
				a[i].dis2=a[i].z-a[i].y;
			}
			else if(a[i].y>=a[i].x&&a[i].y>=a[i].z&&a[i].x>=a[i].z)
			{
				a[i].dis1=a[i].y-a[i].x;
				a[i].dis2=a[i].x-a[i].z;
			}
			else if(a[i].y>=a[i].x&&a[i].y>=a[i].z&&a[i].z>=a[i].x)
			{
				a[i].dis1=a[i].y-a[i].z;
				a[i].dis2=a[i].z-a[i].x;
			}
			else if(a[i].z>=a[i].y&&a[i].z>=a[i].x&&a[i].x>=a[i].y)
			{
				a[i].dis1=a[i].z-a[i].x;
				a[i].dis2=a[i].x-a[i].y;
			}
			else if(a[i].z>=a[i].y&&a[i].z>=a[i].x&&a[i].y>=a[i].x)
			{
				a[i].dis1=a[i].z-a[i].y;
				a[i].dis2=a[i].y-a[i].x;
			}
			
		} 
		sort(a+1,a+n+1,cmp);
		/*for(int i=1;i<=n;i++)
		{
			cout<<a[i].x<<" "<<a[i].y<<" ";
			cout<<a[i].dis1<<" "<<a[i].dis2<<endl;
			
		}*/
		for(int i=1;i<=n;i++)
		{
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z)
			{
				if(btop+1>k)
				{
					if(a[i].y>a[i].z)c[++ctop]=a[i].y;
					else if(a[i].z>=a[i].y)d[++dtop]=a[i].z;
				}
				else b[++btop]=a[i].x;
			}
			else if(a[i].y>=a[i].x&&a[i].y>=a[i].z)
			{
				if(ctop+1>k)
				{
					if(a[i].x>a[i].z)b[++btop]=a[i].x;
					else if(a[i].z>=a[i].x)d[++dtop]=a[i].z;
				}
				else c[++ctop]=a[i].y;
				
			}
			else if(a[i].z>=a[i].x&&a[i].z>=a[i].y)
			{
				if(dtop+1>k)
				{
					if(a[i].x>a[i].y)b[++btop]=a[i].x;
					else if(a[i].y>=a[i].x)c[++ctop]=a[i].y;
				}
				else d[++dtop]=a[i].z;
			}
		 } 
		ll ans=0;
		for(int i=1;i<=btop;i++)
		{
			ans+=b[i];
			//cout<<b[i]<<" ";
		}
		//cout<<endl;
		for(int i=1;i<=ctop;i++)
		{
			ans+=c[i];
			//cout<<c[i]<<" ";
		}
		for(int i=1;i<=dtop;i++)ans+=d[i];
		//cout<<"\n"<<btop<<" "<<ctop<<"\n";
		cout<<ans<<"\n";	
	}
	return 0;
}
