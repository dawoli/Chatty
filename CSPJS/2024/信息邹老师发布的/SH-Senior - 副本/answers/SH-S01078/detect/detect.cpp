#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5,maxl=1e6+5;
long long t,n,m,l,v_l,f[maxl],g[maxl],g2[maxl],d[maxn],v[maxn],a[maxn],ans,cnt;//²î·Ö 
bool check(long long left,long long right)
{
	return g2[right]-g2[left-1]>0;
}
struct need{
	int x,y;
}car[maxn];
bool cmp(need g,need h)
{
	return g.y<h.y||g.y==h.y&&g.x<h.x;
}
int main()
{
	freopen("detect.in","r",stdin); 
	freopen("detect.out","w",stdout); 
	cin>>t;
	while(t--)
	{
		cnt=0;
		ans=0;
		cin>>n>>m>>l>>v_l;//v_limit
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		memset(d,0,sizeof(d));
		memset(v,0,sizeof(v));
		memset(a,0,sizeof(a));
		memset(g,0,sizeof(g));
		memset(g2,0,sizeof(g2));
		for(int i=1;i<=n;i++) car[i].x=0;
		for(int i=1;i<=n;i++) car[i].y=0;
		int k=0;
		for(long long i=1;i<=n;i++)
			cin>>d[i]>>v[i]>>a[i];
		for(long long i=1;i<=m;i++)
		{
			int x;
			cin>>x;
			g[x]++;
		}
		g2[1]=g[1];
		for(long long i=2;i<=l;i++)
			g2[i]=g2[i-1]+g[i];
		for(long long i=1;i<=n;i++)
		{
			if(v[i]>v_l&&a[i]>=0)
			{
				f[d[i]]++;
				if(check(d[i],l)){
					car[++k].x=d[i];
					car[k].y=l;
					cnt++;
				}
			}
			if(v[i]>v_l&&a[i]<0){
				f[d[i]]++;
				if((d[i]+((v_l)*(v_l)-v[i]*v[i])/(a[i]*2)+(((v_l)*(v_l)-v[i]*v[i])%(a[i]*2)==0?0:1))<=l)
				{
					f[d[i]+((v_l)*(v_l)-v[i]*v[i])/(a[i]*2)+(((v_l)*(v_l)-v[i]*v[i])%(a[i]*2)==0?0:1)]--;
					if(check(d[i],d[i]+((v_l)*(v_l)-v[i]*v[i])/(a[i]*2)+(((v_l)*(v_l)-v[i]*v[i])%(a[i]*2)==0?0:1)-1)){
					car[++k].x=d[i];
					car[k].y=d[i]+((v_l)*(v_l)-v[i]*v[i])/(a[i]*2)+(((v_l)*(v_l)-v[i]*v[i])%(a[i]*2)==0?0:1)-1;
					cnt++;
					}
				}
				else
				{ 
					if(check(d[i],l)){
						car[++k].x=d[i];
						car[k].y=l;
						cnt++;
					}
				} 
			}
			if(v[i]==v_l&&a[i]>0)
			{
				f[d[i]+1]++;
				if(check(d[i]+1,l)){
					car[++k].x=d[i+1];
					car[k].y=l;
					cnt++;
				}
			}
			if(v[i]==v_l&&a[i]<0){
				f[d[i]]++;
				f[d[i]+1]--;
				if(check(d[i],d[i])){
					car[++k].x=d[i];
					car[k].y=d[i];
					cnt++;
				}
			}
			if(v[i]<v_l&&a[i]>0){
				if(d[i]+((v_l)*(v_l)-v[i]*v[i])/(a[i]*2)+1<=l)
				{
					f[d[i]+((v_l)*(v_l)-v[i]*v[i])/(a[i]*2)+1]++;
					if(check(d[i]+((v_l)*(v_l)-v[i]*v[i])/(a[i]*2)+1,l)){
						car[++k].x=d[i]+((v_l)*(v_l)-v[i]*v[i])/(a[i]*2)+1;
						car[k].y=l;
						cnt++;
					}
				}
				
			}
		}
		sort(car+1,car+k+1,cmp);
//		cout<<endl;
//		for(int i=1;i<=k;i++) cout<<car[i].x<<' '<<car[i].y<<' ';
//		cout<<endl; 
		for(int i=1;i<=k;i++)
		{
			if(car[i].x==0) continue;
			ans++;
			int p=0;
			for(int j=car[i].y;j>=car[i].x;j--)
			{
				if(g[j])
				{
					p=j;
					break;
				}
			}
			for(int j=1;i+j<=k;j++)
			{
				if(car[i+j].x<=p) car[i+j].x=0;
			}
		}
		cout<<cnt<<' '<<m-ans<<endl;
	}
} 
//		for(int i=1;i<=l;i++)
//		{
//			cout<<f[i]<<' ';
//		}
//		cout<<endl;
//		for(int i=1;i<=l;i++)
//		{
//			cout<<g[i]<<' ';
//		}
//		cout<<endl;
//		for(int i=1;i<=l;i++)
//		{
//			cout<<g2[i]<<' ';
//		}
//		cout<<endl;
