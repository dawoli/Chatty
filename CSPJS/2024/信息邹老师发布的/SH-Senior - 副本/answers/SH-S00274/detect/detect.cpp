#include<bits/stdc++.h>
using namespace std;
long long d[100010],v[100010],a[100010],p[100010],x[30],k[30];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	long long i,j,t,zz,ma,tmp,ami,num,n,m,l,v0,b,c,tot,ama;
	cin>>t;
	for(zz=1;zz<=t;zz++)
	{
		ami=2000; num=0;
		cin>>n>>m>>l>>v0;
		for(i=1;i<=n;i++) cin>>d[i]>>v[i]>>a[i];
		for(i=1;i<=m;i++) {cin>>p[i];}
		sort(p+1,p+m+1);
		ma=p[m];
		for(i=1;i<=n;i++) ami=min(ami,a[i]);
		if(ami>=0)
		{
			for(i=1;i<=n;i++)
			{
				if(d[i]<=ma&&((v[i]*v[i]+2*a[i]*(ma-d[i]))>v0*v0)) num++;
			}
			cout<<num<<" ";
			if(num) cout<<m-1<<endl;
			if(num==0) cout<<m<<endl;
		}
		if(ami<0&&n<=20&&m<=20)
		{
			for(i=0;i<30;i++)
			{
				k[i]=0;x[i]=0;
			}
			for(i=1;i<=n;i++)
			{
				b=0;
				for(j=1;j<=m;j++)
				{
					if(d[i]<=p[j]&&((v[i]*v[i]+2*a[i]*(p[j]-d[i]))>v0*v0)) b=1;
				}
				if(b) num++;
				if(b) k[i]=1;
			}
			cout<<num<<" ";
			if(num==0) cout<<m<<endl;
			if(num!=0)
			{
				ama=100;
				for(tmp=1;tmp<(1<<m);tmp++)
				{
					tot=1;
					c=0;
					for(i=1;i<=m;i++) x[i]=(tmp&(1<<(i-1)))/(1<<(i-1));
					for(i=1;i<=m;i++) c+=x[i];
					if(c>=ama) break;
					for(i=1;i<=n;i++)
					{
						if(k[i]==0) continue;
						b=0;
						for(j=1;j<=m;j++)
						{
							if(x[j]==0) continue;
							if(d[i]<=p[j]&&((v[i]*v[i]+2*a[i]*(p[j]-d[i]))>v0*v0)) b=1;
						}
						if(b==0) tot=0;
					}
					if(tot) ama=min(c,ama);
				}
				cout<<m-ama<<endl;
			}
		}
	}
	return 0;
}
