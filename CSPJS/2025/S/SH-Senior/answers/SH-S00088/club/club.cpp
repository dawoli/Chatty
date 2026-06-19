#include<bits/stdc++.h>
using namespace std;
struct node2{
	long long v,id;
} r[5];
struct node3{
	long long x,y,z;
	long long id1,id2,id3;
} a[100001];
bool cmp(node2 x,node2 y)
{
	return x.v>y.v;
}
long long  n,t;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--)
	{
		long long  f=0;
		long long ans=0;
		priority_queue<long long,vector<long long>,greater<long long> > a1,a2,a3;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>r[1].v>>r[2].v>>r[3].v;
			r[1].id=1,r[2].id=2,r[3].id=3;
			sort(r+1,r+4,cmp);
			a[i].x=r[1].v,a[i].y=r[2].v,a[i].z=r[3].v;
			a[i].id1=r[1].id,a[i].id2=r[2].id,a[i].id3=r[3].id;
		}
		/*for(int i=1;i<=n;i++)
		{
			cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].z<<endl;
			cout<<a[i].id1<<" "<<a[i].id2<<" "<<a[i].id3<<endl<<endl;
		}*/
		for(int i=1;i<=n;i++)
		{
			if(f==0)
			{
				if(a[i].id1==1) 
				{
					a1.push(a[i].x-a[i].y);
					if((long long)(a1.size())>=n/2) f=1;
				}
				if(a[i].id1==2) 
				{
					a2.push(a[i].x-a[i].y);
					if((long long)(a2.size())>=n/2) f=2;
				}
				if(a[i].id1==3) 
				{
					a3.push(a[i].x-a[i].y);
					if((long long)(a3.size())>=n/2) f=3;
				}
				ans+=a[i].x;
			}
			else if(f==1)
			{
				if(a[i].id1==1)
				{
					if((a[i].x-a1.top()>a[i].y) || (a[i].x-a1.top()==a[i].y && a[i].x-a[i].y<a1.top()))
					{
						ans+=a[i].x-a1.top();
						a1.pop();
						a1.push(a[i].x-a[i].y);
					}
					else ans+=a[i].y;
				}
				else ans+=a[i].x;
			}
			else if(f==2)
			{
				if(a[i].id1==2)
				{
					if((a[i].x-a2.top()>a[i].y) || (a[i].x-a2.top()==a[i].y && a[i].x-a[i].y<a2.top()))
					{
						ans+=a[i].x-a2.top();
						a2.pop();
						a2.push(a[i].x-a[i].y);
					}
					else ans+=a[i].y;
				}
				else ans+=a[i].x;
			}
			else
			{
				if(a[i].id1==3)
				{
					if((a[i].x-a3.top()>a[i].y) || (a[i].x-a3.top()==a[i].y && a[i].x-a[i].y<a3.top()))
					{
						ans+=a[i].x-a3.top();
						a3.pop();
						a3.push(a[i].x-a[i].y);
					}
					else ans+=a[i].y;
				}
				else ans+=a[i].x;
			}
			//cout<<ans<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}
