#include<bits/stdc++.h>
using namespace std;
int t,n,m,l,v1,ans,ans1;
long long q,p1;
bool s=true,t1=true;
int do1();
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
		do1();
	return 0;	
} 

int do1()
{
	cin>>n>>m>>l>>v1;
	s=true;t1=true;ans=0;ans1=0;
	int d[n],a[n],v[n],p[m],x=1,y=1;
	memset(a,0,n); 
	while(x<=n)
	{
		cin>>d[y]>>v[y]>>a[y];
		p1=v[y]*v[y]+2*a[y]*(l-d[y]);
		q=v1*v1;
		if(v[y]<=v1 && q>=p1)
		{
			d[y]=0;
			v[y]=0;
			a[y]=0;
			y--;
		}
		if(a[y+1]<0) s=false;
		if(a[y+1]!=0) t1=false; 
		x++;y++;
	}
	if(t1==true)
	{
		for(int i=1;i<=n;i++)
		{
			if(d[i]<=p[m]) ans++;
		}
		cout<<ans<<" ";
		if(ans==0) cout<<m<<endl;
		else cout<<m-1<<endl;
		return 0;
	}
	x--;y--;
	for(int i=1;i<=m;i++)
		cin>>p[i];
	for(int i=1;i<=n;i++)
	{
		s=false;
		for(int j=1;j<=m;j++)
		{
			p1=v[i]*v[i]+2*a[i]*(p[j]-d[i]);
			if(s==false && d[i]<=p[i] && p1>q)
			{
				ans++;
				s=true;
			}
		}
	}
	if(s==true && ans>0) ans1=m-1;
	if(s==true && ans==0) ans=m;
	cout<<ans<<" "<<ans1;
	return 0;
}
