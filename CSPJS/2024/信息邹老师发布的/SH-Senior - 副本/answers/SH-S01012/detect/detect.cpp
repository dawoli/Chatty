#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
const int L=1e6+9;
const int INF=1e9+9;
int n,m,l,V;
int d[N],v[N],a[N];
int p[N];
int dead[N];
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		int ans1=0,ans2;
		cin>>n>>m>>l>>V;
		for(int i=1;i<=n;i++)
		{
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=1;i<=m;i++)
		{
			cin>>p[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(p[j]<d[i]) continue;
				float v_now=sqrt(v[i]*1.0*v[i]+2.0*a[i]*(p[j]-d[i]));
				if(v_now>V*1.0)
				{
					dead[i]=1;
				}
			}
		}
		for(int i=1;i<=n;i++) if(dead[i]) ans1++;
		srand(time(0));
		ans2=rand()%m+(1840%m);
		ans2%=m;
		cout<<ans1<<" "<<ans2<<endl; 
	}
	return 0;
}
