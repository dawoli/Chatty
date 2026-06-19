#include<bits/stdc++.h>
using namespace std;
int t,n,m,l,v,ans,ans1;
int d,s,a,tmp,p[100005];
bool k=false;
const double minn=0.000001;
struct str
{
	double x,y;
}c[100005];
bool cmp(str x,str y)
{
	return x.y<y.y;
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	for(int idk=0;idk<t;idk++)
	{
		k=false;
		cin>>n>>m>>l>>v;
		tmp=0;
		ans=0;
		ans1=0;
		for(int i=0;i<n;i++)
		{
			cin>>d>>s>>a;
			if(s>v&&a>=0)
			{
				c[i].x=d;
				c[i].y=1000001.5;
				ans1++;
			}
			else if(s<=v&&a<=0) c[i].x=d,c[i].y=d-1;
			else if(s<=v&&a>0)
			{
				c[i].x=d+(v*v-s*s)/(2*a*1.0)-minn;
				c[i].y=1000001.5;
				ans1++;
			}
			else
			{
				c[i].x=d;
				c[i].y=d+(v*v-s*s)/(2*a*1.0)-minn;
				ans1++;
			}
		}
		for(int i=0;i<m;i++) cin>>p[i];
		p[m]=1e9;
		sort(c,c+n,cmp);
		tmp=0;
		for(int i=0;i<n;i++)
		{
			while(p[tmp+1]*1.0<c[i].y-minn&&tmp+1<m)
			{
				if(!k)
					ans++;
				k=false;
				tmp++;
			}
			if(c[i].x>c[i].y) continue;
			if(p[tmp]+0.0<c[i].x)
			{
				ans1--;
				continue;
			}
			k=true;
		}
		if(ans1==0) cout<<ans1<<' '<<m<<endl;
		else cout<<ans1<<' '<<ans<<endl;
	}
	return 0;
}
//  idk = I don't know
