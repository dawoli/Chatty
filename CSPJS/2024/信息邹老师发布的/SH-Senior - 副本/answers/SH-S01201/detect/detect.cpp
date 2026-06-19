#include <iostream>
#include <fstream>
#include <algorithm>
#define EIN fin
#define EOUT fout
using namespace std;
ifstream fin("detect.in");
ofstream fout("detect.out");
long long t,n,m,l,v,a,b,c,ans,anx,ld[100010],lv[100010],la[100010],lp[100010],lc[100010][2],lne[1000010],lla[1000010];
bool f,tf[100010];
void funcd(long long p,long long k)
{
	if(p==m+1)
	{
		long long ax=0,a,b;
		for(a=1;a<=n;a++)
			for(b=lc[a][0];b<=lc[a][1];b++)
				if(tf[b])
				{
					ax++;
					break;
				}
		if(ax==ans)
			anx=min(anx,k);
		return;
	}
	funcd(p+1,k);
	tf[p]=1;
	funcd(p+1,k+1);
	tf[p]=0;
}
void funcin()
{
	for(a=1;a<=n;a++)
	{
		EIN>>ld[a]>>lv[a]>>la[a];
		lc[a][0]=0;
		lc[a][1]=0;
	}
	for(a=1;a<=m;a++)
		EIN>>lp[a];
	sort(lp+1,lp+m+1);
	
	for(a=1;a<=l+1;a++)
	{
		lla[a]=0;
		lne[a]=m+1;
	}
	b=1;
	for(a=1;a<=m;a++)
		while((lp[a]>=b)&&(b<=l))
		{
			lne[b]=a;
			b++;
		}
	b=l;
	for(a=m;a>=1;a--)
		while((lp[a]<=b)&&(b>=1))
		{
			lla[b]=a;
			b--;
		}
}
void funcma()
{
	if(la[a]==0)
	{
		lc[a][0]=b;
		lc[a][1]=m;
		ans++;
	}
	else if(la[a]>0)
	{
		c=v*v-lv[a]*lv[a];
		b=lne[min(c/2/a+1+ld[a],l+1)];
		if(b<=m)
		{
			lc[a][0]=b;
			lc[a][1]=m;
			ans++;
		}
	}
	else
	{
		if(lv[a]*lv[a]+2*la[a]*(lp[b]-ld[a])<=v*v)
			return;
		lc[a][0]=b;
		b=lla[min((v*v-lv[a]*lv[a])/2/la[a]+ld[a],l)];
		b--;
		lc[a][1]=b;
		ans++;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	EIN>>t;
	while(t--)
	{
		ans=0;
		f=1;
		EIN>>n>>m>>l>>v;
		if(n>1000)
		{
			funcin();
			for(a=1;a<=n;a++)
			{
				if(lne[931867]==1434)
					cout<<a;
				
				if(la[a]<0)
					f=0;
				if((la[a]==0)&&(lv[a]<=v))
					continue;
				b=lne[ld[a]];
				if(b>m)
					continue;
				funcma();
			}
			EOUT<<ans<<' ';
			if(f)
				EOUT<<m-(ans>0)<<'\n';
			else
			{
				anx=m;
				for(a=1;a<=m;a++)
					tf[a]=0;
				funcd(1,0);
				EOUT<<m-anx<<'\n';
			}
		}
		else
		{
			for(a=1;a<=n;a++)
			{
				EIN>>ld[a]>>lv[a]>>la[a];
				lc[a][0]=0;
				lc[a][1]=0;
			}
			for(a=1;a<=m;a++)
				EIN>>lp[a];
			sort(lp+1,lp+m+1);
			for(a=1;a<=n;a++)
			{
				if(la[a]<0)
					f=0;
				
				
				if((la[a]==0)&&(lv[a]<=v))
					continue;
				b=1;
				while((ld[a]>lp[b])&&(b<=m))
					b++;
				if(b>m)
					continue;
				
				if(la[a]==0)
				{
					lc[a][0]=b;
					lc[a][1]=m;
					ans++;
				}
				else if(la[a]>0)
				{
					while((lv[a]*lv[a]+2*la[a]*(lp[b]-ld[a])<=v*v)&&(b<=m))
						b++;
					if(b<=m)
					{
						lc[a][0]=b;
						lc[a][1]=m;
						ans++;
					}
				}
				else
				{
					if(lv[a]*lv[a]+2*la[a]*(lp[b]-ld[a])<=v*v)
						continue;
					lc[a][0]=b;
					while((lv[a]*lv[a]+2*la[a]*(lp[b]-ld[a])>v*v)&&(b<=m))
						b++;
					b--;
					if(b>m)
						lc[a][1]=m;
					else
						lc[a][1]=b;
					ans++;
				}
			}
			EOUT<<ans<<' ';
			
			
			if(f)
				EOUT<<m-(ans>0)<<'\n';
			else
			{
				anx=m;
				for(a=1;a<=m;a++)
					tf[a]=0;
				funcd(1,0);
				EOUT<<m-anx<<'\n';
			}
		}
	}
	fin.close();
	fout.close();
	return 0;
}
