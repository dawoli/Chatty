#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 100010
int d[N],v[N],a[N],p[N];
pair <int,int> b[N],bb[N];
signed main ()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int tt;
	cin>>tt;
	while(tt--)
	{
		int n,m,l,t,c=0,cc=0,cnt=0,minn=1e12,q=-1e12;
		cin>>n>>m>>l>>t;
		for(int i=1;i<=n;i++) cin>>d[i]>>v[i]>>a[i];
		for(int i=1;i<=m;i++) cin>>p[i];
		for(int i=1;i<=n;i++)
		{
			if(a[i]>0)
			{
				if(v[i]>t)
				{
					int pos=lower_bound(p+1,p+m+1,d[i])-p;
					if(pos<=m) b[++c]=make_pair(pos,m);
				}
				else
				{
					double tmp=1.0*(t-v[i])/a[i];
					double s=v[i]*tmp+a[i]*tmp*tmp/2; 
					int x=floor(s)+d[i]+1;
					int pos=lower_bound(p+1,p+m+1,x)-p;
					if(pos<=m) b[++c]=make_pair(pos,m);
				}
			}
			else if(a[i]==0)
			{
				if(v[i]>t)
				{
					int pos=lower_bound(p+1,p+m+1,d[i])-p;
					if(pos<=m) b[++c]=make_pair(pos,m);
				}
			}
			else
			{
				if(v[i]>t)
				{
					double tmp=1.0*(v[i]-t)/(-a[i]);
					double s=v[i]*tmp+a[i]*tmp*tmp/2;
					int x=ceil(s)+d[i]-1;
					int ll=lower_bound(p+1,p+m+1,d[i])-p;
					int rr=upper_bound(p+1,p+m+1,x)-p-1;
					if(ll<=m&&ll<=rr) b[++c]=make_pair(ll,rr);
				}
			}
		}
		cout<<c<<" ";
		sort(b+1,b+c+1);
		for(int i=c;i>=1;i--)
		{
			if(b[i].second<minn)
			{
				bb[++cc]=b[i];
				minn=b[i].second;
			}
		}
		for(int i=cc;i>=1;i--)
		{
			if(bb[i].first>q)
			{
				q=bb[i].second;
				cnt++;
			}
		}
		cout<<m-cnt<<endl; 
	}
	return 0;
}

