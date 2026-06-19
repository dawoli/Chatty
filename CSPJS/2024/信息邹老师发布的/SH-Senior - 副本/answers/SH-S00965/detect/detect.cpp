#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN=1e5+5;
int t,n,m,l,v;
struct node{
	int d,v,a;
}car[MAXN];
int maxpos=-1;
int pos[MAXN];

int solve2()
{
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(car[i].a==0)
		{
			if(car[i].v>v&&pos[m]>=car[i].d) ans++;
			continue;
		}
		int ds=v*v-car[i].v*car[i].v;
		if(ds<0)
			if(car[i].d<=pos[m]) ans++;
		if(ds>=0) if(car[i].d*2*car[i].a+ds<pos[m]*2*car[i].a) ans++;
	}
	cout<<ans<<" ";
	if(ans==0) cout<<m<<endl;
	else cout<<m-1<<endl;
}

signed main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>l>>v;
		for(int i=1;i<=n;i++) cin>>car[i].d>>car[i].v>>car[i].a;
		for(int i=1;i<=m;i++) cin>>pos[i];
		solve2();
	}
 } 
