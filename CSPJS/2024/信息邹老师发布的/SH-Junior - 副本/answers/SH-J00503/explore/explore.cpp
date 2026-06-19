#include<bits/stdc++.h>

using namespace std;

long long t,n,m,k,ans,x,y,d,e,f;

bool a[1010][1010],b[1010][1010];

int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		ans=0;
		//cin
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int j=1;j<=n;j++)//the plane
		{
			for(int p=1;p<=m;p++)
			{
				char c;
				cin>>c;
				if(c=='x')
				{
					a[j][p]=1;
				}
				else
				{
					a[j][p]=0;
				}
			}
		}
		b[x][y]=1;
		e=x;
		f=y;
		for(int j=1;j<=k;j++)//the jth step
		{
			if(d==0)
			{
				if(a[e][f+1]==1||e<=0||e>n||f+1<=0||f+1>m)
				{
					d=(d+1)%4;
				}
				else
				{
					b[e][f+1]=1;
					f+=1;//robot_pos
				}
				
			}
			else if(d==1)
			{
				if(a[e+1][f]==1||e+1<=0||e+1>n||f<=0||f>m)
				{
					d=(d+1)%4;
				}
				else
				{
					b[e+1][f]=1;
					e+=1;//robot_pos
				}
			}
			else if(d==2)
			{
				if(a[e][f-1]==1||e<=0||e>n||f-1<=0||f-1>m)
				{
					d=(d+1)%4;
				}
				else
				{
					b[e][f-1]=1;
					f-=1;//robot_pos
				}
			}
			else if(d==3)
			{
				if(a[e-1][f]==1||e-1<=0||e-1>n||f<=0||f>m)
				{
					d=(d+1)%4;
				}
				else
				{
					b[e-1][f]=1;
					e-=1;//robot_pos
				}
			}
		}
		for(int j=1;j<=n;j++)//how many 1
		{
			for(int p=1;p<=m;p++)
			{
				if(b[j][p]==1)
				{
					ans++;
				} 
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
