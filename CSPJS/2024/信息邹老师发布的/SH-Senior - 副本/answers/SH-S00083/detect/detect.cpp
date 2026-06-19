#include<bits/stdc++.h>
using namespace std;
struct node{
	float l;
	float r;
} c[100001];
long long n,m,L,V,T,p,cnt2;
float s[100001];
float l[100001],r[100001];
vector<int> mm[100001];
bool ss[100001];
inline long long read()
{
	long long x=0,f=1;
	char ch;
	ch=getchar();
	while(ch<'0' || ch>'9') 
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
void add(long long d,long long v,long long a)
{
	if(a>0)
	{
		if(v>V) 
		{
			c[++p].l=d;
			c[p].r=L;
		}
		if(v==V) 
		{
			c[++p].l=float(d*1.0)+0.1;
			c[p].r=L;
		}
		if(v<V)
		{
			float vv;
			vv=sqrt(V*V+2*a*(L-d));
			if(abs(vv-V)<1e-6) 
			{
				c[++p].l=d+float((V*V-v*v)*1.0/(a*2)*1.0);
				c[p].r=L-0.1;
			}
			else
			{
				if(vv>V)
				{
					c[++p].l=d+float((V*V-v*v)*1.0/(a*2)*1.0);
					c[p].r=L;
				}
			}
		}
	}
	if(a==0)
	{
		if(v>V)
		{
			c[++p].l=d;
			c[p].r=L;
		}
	}
	if(a<0)
	{
		if(v>V)
		{
			if(V*V+2*a*(L-d)>0)
			{
				float vv;
				vv=sqrt(V*V+2*a*(L-d));
				if(abs(vv-V)<1e-6) 
				{
					c[++p].l=d;
					c[p].r=L-0.1;
				}
				else
				{
					if(vv>V)
					{
						c[++p].l=d;
						c[p].r=L;
					}
					else
					{
						c[++p].l=d;
						c[p].r=d+float((V*V-v*v)*1.0/(a*2)*1.0);
					}
				}
			}
			else
			{
				c[++p].l=d;
				c[p].r=d+float((V*V-v*v)*1.0/(a*2)*1.0);
			}
		}
	}
	return ;
}
bool cmp(node a,node b)
{
	if(a.l!=b.l) return a.l<b.l;
	else return a.r<b.r;
}
void solve(int pp)
{
	if(pp>m)
	{
		bool st[100001];
		memset(st,0,sizeof(ss));
		int cnt=0,f=1;
		for(int i=1;i<=m;i++)
		{
			if(ss[i])
			{
				for(int j=0;j<mm[i].size();j++) st[mm[i][j]]=1;
				cnt++;
			}
		}
		for(int i=1;i<=p;i++) if(!st[i]) f=0;
		if(f) cnt2=max(cnt2,(long long)(cnt));
		return ;
	}
	ss[pp]=0;
	solve(pp+1);
	ss[pp]=1;
	solve(pp+1);
	return ;
}
int main()
{
	//freopen("detect.in","r",stdin);
	//freopen("detect.out","w",stdout);
	/*q.push(1);
	q.push(2);
	while(!q.empty())
	{
		cout<<q.top()<<" ";
		q.pop();
	}*/
	T=read();
	while(T--)
	{
		memset(ss,0,sizeof(ss));
		cnt2=10000000;
		p=0;
		n=read(),m=read(),L=read(),V=read();
		for(int i=1;i<=m;i++) mm[m].clear();
		long long d,v,a,cnt=0,cc=1,cnt2=0;
		for(int i=1;i<=n;i++)
		{
			d=read(),v=read(),a=read();
			add(d,v,a);
		}
		sort(c+1,c+p+1,cmp);
		for(int i=1;i<=p;i++) cout<<c[i].l<<" "<<c[i].r<<endl;
		cout<<endl;
		int ll,rr;
		for(int i=1;i<=m;i++)
		{
			
			s[i]=read()*1.0;
			for(int j=1;j<=p;j++) if(c[j].l<=s[i] && c[j].r>=s[i]) mm[i].push_back(j);
			int f1=0,f2=0;
			while((c[cc].l<=s[i]) && cc<=p)
			{
				if(c[cc].r>=s[i])
				{
					cnt++;
				}
				cc++;
			}
			//cout<<i<<" "<<cnt2<<endl<<endl;
		}
		solve(1);
		cout<<cnt<<" "<<p-cnt2<<endl;
		//for(int i=1;i<=p;i++) cout<<l[i]<<" "<<r[i]<<endl;
	}
	return 0;
}
