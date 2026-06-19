#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;

int T,n,m,L,cnt,ans;
double V,d[N],v[N],a[N],p[N],dx[N];

struct line{
	int l,r;
}c[N];

void init()
{
	for(int i=1;i<=n;i++) c[i].l=m+1,c[i].r=m+1;
	cnt=0,ans=1;
}

int binary(double u)
{
	int l=1,r=m;
	while(l<r)
	{
		int mid=l+r>>1;
		if(u==p[mid]) return mid;
		if(u<p[mid]) r=mid;
		else l=mid+1;
	}
	return l;
}

bool cmp(line c1,line c2)
{
	if(c1.l==c2.l) return c1.r<c2.r;
	return c1.l<c2.l;
}

int main()
	{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(int I=1;I<=T;I++)
	{
		cin>>n>>m>>L>>V;
		init();
		for(int i=1;i<=n;i++) cin>>d[i]>>v[i]>>a[i];
		for(int i=1;i<=m;i++) cin>>p[i];
		sort(p+1,p+m+1);
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				if(v[i]<=V||d[i]>p[m]) continue;
				c[i].l=binary(d[i]);
				c[i].r=m;
				cnt++;
				
//				cout<<c[i].l<<" "<<c[i].r<<" "<<d[i]+dx[i]<<endl;
				
			}
			if(a[i]>0)
			{
				if(sqrt(v[i]*v[i]-2*a[i]*(p[m]-d[i]))<=V||d[i]>p[m]) continue;
				dx[i]=V*V-v[i]*v[i];
				dx[i]/=2*a[i];
				c[i].l=binary(d[i]+dx[i]);
//				if(p[c[i].l]==d[i]+dx[i]) c[i].l++;
				c[i].r=m;
				cnt++;
				
//				cout<<c[i].l<<" "<<c[i].r<<" "<<d[i]+dx[i]<<endl;
				
			}
			if(a[i]<0)
			{
				if(v[i]<=V||d[i]>p[m]) continue;
				dx[i]=V*V-v[i]*v[i];
				dx[i]/=2*a[i];
				c[i].l=binary(d[i]);
				if(v[i]*v[i]+2*a[i]*(p[c[i].l]-d[i])<=V*V)
				{
					c[i].l=m+1;
					c[i].r=m+1;
					continue;
				}
				c[i].r=binary(d[i]+dx[i]);
				if(p[c[i].r]>d[i]+dx[i]) c[i].r--;
				if(p[c[i].r]<d[i]||p[c[i].l]>d[i]+dx[i])
				{
					c[i].l=m+1,c[i].r=m+1;
					continue;
				}
				cnt++;
				
//				cout<<i<<" ";
//				cout<<c[i].l<<" "<<c[i].r<<" "<<d[i]+dx[i]<<endl;
				
			}
		}
		
//		cout<<endl;
		
//		for(double i=1;i<=L;i++) cout<<binary(i)<<" ";
//		cout<<c[3].l<<" "<<c[3].r<<" "<<dx[3]<<endl;
//		cout<<endl;
		
		cout<<cnt<<" ";
		if(cnt==0)
		{
			cout<<m<<endl;
			continue;
		}
		sort(c+1,c+n+1,cmp);
		int r=m+1;
		for(int i=1;i<=cnt;i++)
		{
			r=min(r,c[i].r);
			if(c[i].l>r)
			{
				ans++;
				r=c[i].r;
			}
		}
		cout<<m-ans<<endl;
	}
	return 0;
	}
