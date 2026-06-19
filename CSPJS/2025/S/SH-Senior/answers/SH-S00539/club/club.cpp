#include <bits/stdc++.h>
using namespace std;
struct man{
	int a,b,c,got;
} p[100001];

bool bmp(man x,man y)
{
	return x.got>y.got; 
}

int n;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int a,b,c;
			cin>>a>>b>>c;
			p[i].a=a;
			p[i].b=b;
			p[i].c=c;
			int ls=max({ p[i].a , p[i].b , p[i].c });
			if(ls==a) p[i].got=a-max(b,c) ;
			else if(ls==b) p[i].got=b-max(a,c);
			else p[i].got=c-max(a,b);
		}
		
		sort(p+1,p+n+1,bmp);
		
		int cla=0,clb=0,clc=0,ans=0;
		for(int i=1;i<=n;i++)
		{
			int ls=max({ p[i].a , p[i].b , p[i].c });
			if(ls==p[i].a)
			{
				if(cla<n/2)
				{
					cla++;
					ans+=p[i].a;
				}
				else ans+=max(p[i].b,p[i].c);
			}
			else if(ls==p[i].b)
			{
				if(clb<n/2)
				{
					clb++;
					ans+=p[i].b;
				}
				else ans+=max(p[i].a,p[i].c);
			}
			else
			{
				if(clc<n/2)
				{
					clc++;
					ans+=p[i].c;
				}
				else ans+=max(p[i].b,p[i].a);
			}
		}
		cout<<ans<<endl;
	}
	

	return 0;
}
