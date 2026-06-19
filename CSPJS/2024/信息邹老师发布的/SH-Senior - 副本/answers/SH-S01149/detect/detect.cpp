#include <bits/stdc++.h>
using namespace std;
struct Cr{
	double d,v,a;
	int start,end;
}c[100001];
int T,n,m,L,V,ans,cnt,idx;
double b[100001];
bool cmp(Cr x,Cr y) { return x.start<y.start||x.start==y.start&&x.end<y.end; }
Cr monitor(Cr x)
{
	if(x.a>0)
	{
		if(x.v<=V)
		{
			double y=x.d+(V*V-x.v*x.v)/(2*x.a);
			if(y>=b[m]) return x;
			x.start=upper_bound(b+1,b+1+m,y)-b;
			x.end=m;
		}
		else
		{
			if(x.d>b[m]) return x;
			x.start=upper_bound(b+1,b+1+m,x.d)-b;
			x.end=m;
		}
	}
	if(x.a==0)
	{
		if(x.v<=V||x.d>b[m]) return x;
		x.start=upper_bound(b+1,b+1+m,x.d)-b;
		x.end=m;
	}
	if(x.a<0)
	{
		if(x.v<=V||x.d>b[m]) return x; 
		double y=x.d+(x.v*x.v-V*V)/(2*abs(x.a));
		int start=lower_bound(b+1,b+1+m,x.d)-b,end=(lower_bound(b+1,b+1+m,y)-b)-1;
		if(end<start) return x;
		x.start=start,x.end=end;
	}
	ans++;
	return x;
}
int main()
{
	ios::sync_with_stdio(0);
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--)
	{
		memset(c,0,sizeof(c));
		memset(b,0,sizeof(b));
		ans=0,cnt=0,idx=0;
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++) cin>>c[i].d>>c[i].v>>c[i].a;
		for(int i=1;i<=m;i++) cin>>b[i];
		for(int i=1;i<=n;i++) c[i]=monitor(c[i]);
		sort(c+1,c+1+n,cmp);
		while(c[idx].start==0) idx++;
		for(int i=idx;i<=n;i++)
		{
			if(c[i].end<c[i+1].start) continue;
			for(int j=i+1;j<=n;j++) if(c[i].end>=c[j].start) c[i].start=c[j].start,c[i].end=min(c[i].end,c[j].end),c[j].start=0,c[j].end=0;
		}
		for(int i=idx;i<=n;i++) if(c[i].start!=0) cnt++;
		cout<<ans<<" "<<m-cnt<<endl;
	}
	return 0;
}
