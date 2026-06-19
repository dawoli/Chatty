#include<bits/stdc++.h>
using namespace std;
int l[100005],r[100005],p;
int n,m,a,d,v,vl,ans,s,b[100005],t[100005],c[100005],dd[100005],cc[100005],T;//vl chusudu
/*vector<int> dd[100005],e[100005];
struct P
{
	int num,id;
	bool operator < (const P &xx) const {
		return num<xx.num;
	}
};
priority_queue<P> f;*/
void meas(int x,int d,int vl,int a)
{
	//cout<<1.0*qq/q<<endl;
	if(vl>v&&a>=0)
	{
		l[x]=d;
		r[x]=s;
	}
	else if(vl<v&&a<=0)
	{
		l[x]=0;
		r[x]=-1;
	}
	else if(vl<v)
	{
		int qq=v*v-vl*vl,q=2*a;
		double p=1.0*qq/q+d;
		//cout<<p<<endl;
		l[x]=ceil(p+0.0000001);
		r[x]=s;
	}
	else if(vl>v)
	{
		int qq=v*v-vl*vl,q=2*a;
		double p=1.0*qq/q+d;
		//cout<<p<<endl;
		l[x]=d;
		r[x]=floor(p-0.0000001);
	}
	else if(v==vl&&a>0)
	{
		l[x]=ceil(d+0.0000001);
		r[x]=s;
	}
	else if(v==vl&&a<=0)
	{
		l[x]=0;
		r[x]=-1;
	}
	else
	{
		cout<<111111111<<endl;
	}
}
void update(int x,int num)
{
	while(x<=s+2)
	{
		t[x]+=num;
		x+=x&(-x);
	}
}
int query(int x)
{
	int sum=0;
	while(x>0)
	{
		sum+=t[x];
		x-=x&(-x);
	}
	return sum;
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++)
	{
		memset(t,0,sizeof(t));
		ans=0;
		cin>>n>>m>>s>>v;
		for(int i=1;i<=n;i++)
		{
			cin>>d>>vl>>a;
			meas(i,d,vl,a);
		}
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&b[i]);
			update(b[i]+1,1);
		}
		for(int i=1;i<=n;i++)
		{
			int u=query(r[i]+1)-query(l[i]);
			//cout<<u<<endl;
			if(l[i]<=r[i]&&u>0)
			{
				c[++ans]=i;
			}
		}
		cout<<ans<<" ";
		/*for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=ans;j++)
			{
				if(b[i]>=l[c[j]]&&b[i]<=r[c[j]])
				{
					dd[i].push_back(c[j]);
					ddd[i]++;
					e[c[j]].push_back(i);
				}
			}
		}
		for(int i=1;i<=m;i++)
			f.push(P{ddd[i],i});
		bool g[100005];
		int h=ans,ansa=0;
		memset(g,0,sizeof(g));
		for(int i=1;i<=m;i++)
		{
			int zz=f.top().id;
			int z=0;
			for(int j=0;j<dd[i].size();j++)
			{
				if(g[dd[i][j]])
				{
					z++;
				}
				else
				{
					g[dd[i][j]]=1;
					//int u=dd[i][j];
					//for(int k=0;k<e[u].size();k++)
					//{
					//	f[e[u][k]].num--;
					//}
				}
			}
			h-=z;
			//for(int j=0;j<=n)
			ansa++;
			if(h<=0)
				break;
		}*/
		int cnt=ans;
		for(int i=1;i<=cnt;i++)
		{
			cc[l[c[i]]]++;
			cc[r[c[i]]+1]--;
		}
		int ansa=0;
		while(ansa<=n)
		{
			ansa++;
			memset(dd,0,sizeof(dd));
			dd[0]=cc[0];
			for(int i=1;i<=s;i++)
			{
				dd[i]=dd[i-1]+cc[i];
				//cout<<dd[i]<<" ";
			}
			//cout<<endl;
			int lz=0,pz;
			//if(ansa==3)
				//break;
			for(int i=1;i<=m;i++)
			{
				if(dd[b[i]]>lz)
				{
					lz=dd[b[i]];
					pz=b[i];
				}
			}
			//cout<<" "<<lz<<endl;
			ans-=lz;
			if(ans<=0)
				break;
			for(int i=1;i<=cnt;i++)
			{
				if(l[c[i]]<=pz&&r[c[i]]>=pz)
				{
					cc[l[c[i]]]--;
					cc[r[c[i]]+1]++;
				}
			}
		}
		cout<<n-ansa;
	}
	return 0;
}
