#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;
int n,m,cntloss,T,ans;
long long L,V,c;
long long d[maxn],v[maxn],a[maxn],p[maxn],pre,minn;
long long cs[maxn],ce[maxn];
bool tec[25],f,de[25];
long long minp,maxp,sump[maxn],nump[maxn],carp[maxn];

void dfs(int idp,int cnt)
{
	
	if(idp>m)
	{
		ans=max(ans,cnt);
		return;
	}
	f=0;
	for(int i=1;i<=n&& de[i];i++)
	{
		if(tec[i])
		{
			f=1;
			break;
		}
	}
	if(!f)
	{
		for(int i=1;i<=n&& de[i];i++)
		{
			if(p[idp]>=cs[i]&&p[idp]<=ce[i])
			{
				carp[i]--;
				if(carp[i]==1)tec[i]=1;
			}
		}
		dfs(idp+1,cnt+1);
		for(int i=1;i<=n&& de[i];i++)
		{
			if(p[idp]>=cs[i]&&p[idp]<=ce[i])
			{
				carp[i]++;
				if(carp[i]!=1)tec[i]=0;
			}
		}
	}
	dfs(idp+1,cnt);
	return;
}


int main()
{
	scanf("%d",&T);
	while(T--)
	{
		memset(nump,0,sizeof nump);
		memset(sump,0,sizeof sump);
		memset(carp,0,sizeof carp);
		memset(tec,0,sizeof tec);
		for(int i=0;i<=24;i++)de[i]=1;
		cntloss=0;
		minn=1e9+7;
		scanf("%d%d%d%d",&n,&m,&L,&V);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&d[i],&v[i],&a[i]);
			if(a[i]==0)
			{
				if(v[i]>V)
				{
					cs[i]=d[i];
					ce[i]=L;
				}
				else
				{
					de[i]=0;
					cntloss++;
				}
			}
			else if(a[i]>0)
			{
				if(v[i]>V)
				{
					cs[i]=d[i];
					ce[i]=L;
				}
				else if(v[i]==V)
				{
					cs[i]=d[i]+1;
					ce[i]=L;
				}
				else
				{
					cs[i]=d[i]+(V*V-v[i]*v[i])/(a[i]*2)+1;
					ce[i]=L;
				}
				if(cs[i]>L)
				{
					de[i]=0;
					cntloss++;
				}
			}
			else
			{
				if(v[i]<=V)
				{
					de[i]=0;
					cntloss++;
				}
				else
				{
					ce[i]=d[i]+(V*V-v[i]*v[i])/(a[i]*2);
					if((V*V-v[i]*v[i])%(a[i]*2)==0)ce[i]--;
					cs[i]=d[i];
				}
				if(ce[i]>L)ce[i]=L;
			}	
			cout<<"cs "<<cs<<" ce "<<ce<<" cnt "<<cntloss<<endl;
		}
		minp=1e9+7;
		maxp=-1;
		cout<<"a ";
		for(int i=1;i<=m;i++)
		{
			scanf("%lld",&p[i]);
			nump[p[i]]++;
		}
		cout<<"b ";
		for(int i=1;i<=p[m];i++)
		{
			sump[i]=sump[i-1]+nump[i];
			cout<<sump[i]<<" ";
		}
		cout<<"c ";
		if(n<=20)
		{
			cout<<"d "; 
			ans=0;
			for(int i=1;i<=n&&de[i];i++)
			{
				carp[i]=sump[ce[i]]-sump[cs[i]-1];
				if(carp[i]==0&&de[i])
				{
					de[i]=1;
					cout<<i<<" ";
					cntloss++;
				}
				else if(carp[i]==1)tec[i]=1;
			}
			cout<<"e ";
			cout<<n-cntloss<<" ";
			dfs(1,0);
			cout<<"f ";
			cout<<ans<<endl;
			cout<<"g ";
		}
		else
		{
			if(a>=0)
			{
				
				for(int i=1;i<=n;i++)
				{
					carp[i]=sump[ce[i]]-sump[cs[i]-1];
					if(carp[i]==0)
					{
						cntloss++;
						continue;
					}
					if(carp[i]>=maxp)
					{
						maxp=carp[i];
						minn=cs[i];
					}
					minp=min(minp,carp[i]-1);
				}
				pre=sump[minn-1];
				cout<<n-cntloss<<" "<<pre+minp<<endl;;
			}
		}
	}
	return 0;
}
