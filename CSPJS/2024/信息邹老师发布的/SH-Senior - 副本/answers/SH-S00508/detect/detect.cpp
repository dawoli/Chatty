#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
struct node
{
	int st,en,id;
}c[100001];
bool cmp(node x,node y)
{
	if(x.en==-1&&y.en==-1)
	{
		return x.id<y.id;
	}
	if(x.en==-1)
	{
		return false;
	}
	if(y.en==-1)
	{
		return true;
	}
	if(x.st!=y.st)return x.st<y.st;
	return x.en<y.en;
}
int t,n,m,l,V,ans,maxc=0;
int p[100001];
bool flag[100001];
void add(int i,int a,int b)
{
	c[i].st=a;
	c[i].en=b;
	c[i].id=i;
}
void dfs(int step,int cnt,const int x)
{
	
	if(step==m+1||c[x].st==-1)
	{
		if(c[x].st==-1)
		{
			cout<<step<<" "<<cnt<<" "<<x<<endl;
			maxc=max(maxc,cnt);
		}
		return;
	}
	//cout<<step<<" "<<cnt<<" "<<x<<endl;
	//no
	if((c[x].st<=step&&step<=c[x].en)||c[x].st==-1)dfs(step+1,cnt+1,x);
	//yes
	int pos=x;
	for(int i=x;i<=n;i++)
	{
		if((c[x].st<=step&&step<=c[x].en)||c[x].st==-1)
		{
			flag[i]=true;
		}
		if(flag[i]==false&&pos==x)
		{
			pos=i;
		}
	}
	if(pos!=x-1)
	{
		dfs(step+1,cnt,pos+1);
	}
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--)
	{
		memset(flag,0,sizeof(flag));
		ans=0;
		maxc=0;
		cin>>n>>m>>l>>V;
		for(int i=1;i<=n;i++)
		{
			int d,v,a;
			cin>>d>>v>>a;
			if(a==0)
			{
				if(v>V)
					add(i,d,l);
				else 
					add(i,-1,-1);
			}
			if(a>0)
			{
				if(v>V)
					add(i,d,l);
				else
				{
					int x=int(1ll*V*V-1ll*v*v)/(2*a)+1;
					if(x<=l)
						add(i,d+x,l);
					else 
						add(i,-1,-1);
				}
			}
			if(a<0)
			{
				if(v>V)
				{
					int x=int(1ll*V*V-1ll*v*v)/(2*a);
					if(int(1ll*V*V-1ll*v*v)%(2*a)==0)x--;
						add(i,d,min(d+x,l));
				}
				else add(i,-1,-1);
			}
		}
		sort(c+1,c+n+1,cmp);
		
		for(int i=1;i<=m;i++)
		{
			cin>>p[i];
		}
		sort(p+1,p+m+1);
		p[m+1]=1e9;
		for(int i=1;i<=n;i++)
		{
			if(c[i].st==-1||c[i].en==-1)
			{
				if(!(c[i].st==-1&&c[i].en==-1))
				{
					cout<<"error";
				}
				continue;
			}
			int* x=lower_bound(p+1,p+m+1,c[i].st);
			//cout<<c[i].st<<" "<<c[i].en<<" "<<x<<endl;
			if(*x<=c[i].en)
			{
				ans++;
				c[i].st=(x-(p+0));
				c[i].en=upper_bound(p+1,p+m+2,c[i].en)-(p+0)-1;
			}
			else
			{
				c[i].st=c[i].en=-1;
			}
		}
		sort(c+1,c+n+1,cmp);
	/*	for(int i=1;i<=n;i++)
		{
			cout<<c[i].st<<" "<<c[i].en<<endl;
		}*/
		//cout<<endl;
		dfs(1,0,1);
		cout<<ans<<" "<<maxc<<endl;
	}
}
