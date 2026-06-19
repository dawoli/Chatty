#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
struct node
{
	int x;
	int v;
	int a;	
}; 
int T;
vector<int> c,ck[maxn];
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--) 
	{
		
		int n=0,m=0,vm=0,ans=0,ans2=0,vis[maxn],f=1,vis2[maxn];
		long long l;
		node v[maxn];
		memset(vis,0,sizeof vis);
		memset(vis2,0,sizeof vis2);
		c.clear();
		cin>>n>>m>>l>>vm;
		ans2=m;
		for(int i=0;i<maxn;i++)
		{
			v[i].x=0;
			v[i].v=0;
			v[i].a=0;
			ck[i].clear();
		}
		for(int i=0;i<n;i++)
		{
			int a=0,b=0,c=0;
			scanf("%d",&a);
			scanf("%d",&b);
			scanf("%d",&c);
			v[i]={a,b,c};
			if(c==0)
			{
				if(b>vm) ans++;
				vis[i]=1;
			}else
			{
				f=0;
			}
		}
		
		for(int i=0;i<m;i++)
		{
			int x;
			scanf("%d",&x);
			c.push_back(x);
		}
		if(f==1)
		{
			cout<<ans<<" "<<m-1<<endl;
			continue;
		}
		int cnt=0;
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(vis[j]||v[j].x>c[i]) continue;
				double vt=0.0;
				vt=sqrt(v[j].v*v[j].v+2*v[j].a*(c[i]-v[j].x));
				if(vt>vm)
				{
					ans++;
					vis[j]++;
					if(v[j].a<0&&vis2[i]==0)
					{
						vis2[i]++;
						ans2--;
					}
				} 
			}
		}
		cout<<ans<<" "<<ans2-1<<endl;
	}
	return 0;	
} 
/*
1
5 5 15 3
0 3 0
12 4 0
1 1 0
5 5 0
6 4 0
2 5 8 9 15
*/
