#include<bits/stdc++.h>
using namespace std;
struct Car
{
	int d,v,a;
}a[100005];
int t,n,m,l,v;
int p[100005];
int ans,sum;
vector<int>g[100005];
bool b[100005];
stack<int>st;
void dfs(int deep,int s)
{
	if(deep>m)
	{
		if(st.size()==ans)
		{
			sum=min(sum,s);
		}
		return;
	}
	dfs(deep+1,s);
	int a=0;
	for(int i=0;i<g[deep].size();i++)
	{
		if(!b[g[deep][i]])
		{
			st.push(g[deep][i]);
			b[g[deep][i]]=true;
			a++;
		}
	}
	dfs(deep+1,s+1);
	while(a--)
	{
		int x=st.top();
		st.pop();
		b[x]=false;
	}
}
int f1(int x)
{
	int s=1,e=m;
	while(s<e)
	{
		int mid=(s+e)/2;
		if(p[mid]==x)return mid;
		if(p[mid]>x)
		{
			e=mid;
		}
		else
		{
			s=mid+1;
		}
	}
	return e;
}
int f2(int x)
{
	int s=1,e=m;
	while(s<e)
	{
		int mid=(s+e+1)/2;
		if(p[mid]==x)return mid;
		if(p[mid]>x)
		{
			e=mid-1;
		}
		else
		{
			s=mid;
		}
	}
	return s;
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>l>>v;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].d>>a[i].v>>a[i].a;
		}
		for(int i=1;i<=m;i++)
		{
			cin>>p[i];
			g[i].clear();
		}
		ans=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i].a==0)
			{
				if(a[i].v>v)
				{
					ans++;
					int s=f1(a[i].d),e=m;
					if(s<=e)ans++;
					for(int j=s;j<=e;j++)
					{
						g[j].push_back(i);
					}
				}
			}
			else if(a[i].a>0)
			{
				int vt=(v*v-a[i].v*a[i].v)/(2.0*a[i].a)+a[i].d;
				if(vt<=l)
				{
					int s=f1(vt),e=m;
					if(p[s]<=vt)s++;
					if(s<=e)ans++;
					for(int j=s;j<=e;j++)
					{
						g[j].push_back(i);
					}
				}
			}
			else
			{
				int vt=ceil((v*v-a[i].v*a[i].v)/(2.0*a[i].a))+a[i].d;
//				cout<<i<<" "<<vt<<endl;
				if(vt>=a[i].d)
				{
					int s=f1(a[i].d),e=f2(vt);
					if(p[e]>=vt)e--;
					if(s<=e)ans++;
					for(int j=s;j<=e;j++)
					{
						g[j].push_back(i);
					}
				}
			}
		}
		cout<<ans<<" ";
		sum=ans;
//		cout<<endl;
//		for(int k=1;k<=m;k++)
//		{
//			for(int j=0;j<g[k].size();j++)
//			{
//				cout<<g[k][j]<<" ";
//			}
//			cout<<endl;
//		}
		dfs(1,0);
		cout<<m-sum<<endl;
	}
	return 0;
}
