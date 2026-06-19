#include <iostream>
#include <cstdio>
using namespace std;
struct Node
{
	int a,d,v;
	int s;
}car[100005];
int main() 
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t,n,m,l,V;
	cin>>t;
	
	
	int p[100005];
	int sum[1000005];
	for(int i=1;i<=t;i++)
	{
		cin>>n>>m>>l>>V;
		for(int j=1;j<=n;j++)
		{
			cin>>car[i].d>>car[i].v>>car[i].a;
			car[i].s = (V*V-car[i].v*car[i].v);
		}
		for(int j=1;j<=m;j++)
		{
			cin>>p[i];
		}
		int ans = 0;
		for(int j=1;j<=n;j++)
		{
			int x,y;
			if(car[i].v>V)
			{
				if(car[i].a>=0)
				{
					ans++;
					x = car[i].d;y = l;
				}
				else
				{
					ans++;
					x= car[i].d;y = car[i].d+car[i].s;	
				}
			}
			else if(car[i].v==V)
			{
				if(car[i].a>0 && car[i].d+car[i].s<=p[m])
				{
					ans++;
					x = car[i].d+car[i].s;y = l;
				}
			}
			else
			{
				if(car[i].a>0 && car[i].d+car[i].s<=p[m])
				{
					ans++;
					x = car[i].d+car[i].s;y=l;
				}
			}
			for(int k=1;k<=m;k++)
			{
				if(p[k]>=x && p[k]<=y)
				{
					sum[p[k]]++;
				}
			}
		}
		cout<<ans<<" "<<m/2+1;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
