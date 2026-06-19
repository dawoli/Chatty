#include<bits/stdc++.h>
using namespace std;
const int M=1e5+5;
struct car{
	int d,v,a,fine;
};
int T,n,m,L,V,tmp,stop[M];
car c[M];
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--)
	{
		int ans=0;
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++)
		{
			cin>>c[i].d>>c[i].v>>c[i].a;
			if(c[i].a<0&&c[i].v<=V)
			{
				c[i].fine=L+1;
			}
			else
			{
				if(c[i].a!=0)
				{
					c[i].fine=c[i].d+(c[i].v*c[i].v+V*V)/(2*c[i].a);
				}
				else if(c[i].a==0)
				{
					if(c[i].v>V)c[i].fine=c[i].d;
					else c[i].fine=L+1;
				}
			}
		}
		for(int i=1;i<=n;i++)cin>>stop[i];
		for(int i=1;i<=n;i++)
		{
			if(c[i].fine>L)continue;
			if(c[i].a<V)
				if(c[i].fine>stop[0])
					ans++;
			else
				if(c[i].fine<stop[m])
					ans++;
		}
		cout<<ans<<" "<<m-2<<endl;
	}
	return 0;
}
