#include<bits/stdc++.h>
using namespace std;

const int N=100005;
int n,m,L,V,cnt;
vector<int>a,v,d;
vector<int>s[N];
bool flag[N];

void ans(int pre[],int last[],int p[]);
bool cmp(const int a,const int b)
{
	return s[a].size()>s[b].size(); 
 }
void solve()
{
	cnt=0;
	int p[N],last[N],pre[N];
	cin>>n>>m>>L>>V;
	for(int i=1;i<=n;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		d.push_back(x);
		v.push_back(y);
		a.push_back(z); 
	}
	for(int i=1;i<=m;i++)
	{
		cin>>p[i];
	}
	for(int i=1;i<=n;i++)
	{
		//if(d[i]+(V*V-v[i]*v[i])/(2*a[i])>L)continue;
		flag[i]=false;
		if(a[i]==0)
		{
			if(v[i]>V+1)flag[i]=true;
		}
		else
		{
			for(int j=1;j<=m;j++)
			{
				//cout<<sqrt(a[i]*a[i]+2*a[i]*p[i])<<endl;
				if(sqrt(v[i]*v[i]+2*a[i]*(p[j]-d[i]))>V)
				{
					flag[i]=true;
					//cout<<j<<" ";
				}
			}
		}
		//cout<<flag<<endl;
		if(!flag[i])continue;
		cnt++;
		if(a[i]>=0&&v[i]>V)
		{
			pre[i]=d[i];
			last[i]=L;
		}
		else if(a[i]<0&&v[i]>V)
		{
			pre[i]=d[i];
			last[i]=d[i]+(V*V-v[i]*v[i])/(2*a[i]);
		}
		else if(a[i]>0&&v[i]<V)
		{
			pre[i]=d[i]+(V*V-v[i]*v[i])/(2*a[i]);
			last[i]=L;
		}
	}
	ans(pre,last,p);
}
void ans(int pre[],int last[],int p[])
{
	set<int>all;
	for(int i=1;i<=m;i++)
	{
		s[i].clear();
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(p[i]>=pre[j]&&p[i]<=last[j])
				s[i].push_back(j);
		}
	}
	int id[m+5];
	for(int i=1;i<=m;i++)
	{
		id[i]=i;
	} 
	sort(id+1,id+m+1,cmp);
	int ans=0,i=1; 
	while(all.size()<cnt)
	{
		ans++;i++;
		for(int j=1;j<=s[id[i]].size();j++)
		{
			all.insert(s[i][j]);
		}
	}
	cout<<cnt<<" "<<ans+1<<endl;
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		a.clear();
		v.clear();
		d.clear();
		solve();
		fill(flag,flag+N+1,false);
	}
 } 
