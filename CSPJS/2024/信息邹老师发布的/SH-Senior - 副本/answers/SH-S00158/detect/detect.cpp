#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int T,n,m,L,V,i,j,k,mo[maxn],cnt,ans,qjl[maxn];
bool wa,wb,wc,che,vis[maxn];
double d1;
vector<int> chao,ls[maxn];
struct node
{
	int d,v,a;
}ca[maxn];
void dfs(int x,int sum,int num)
{
	if (sum==chao.size())
	{
		ans=min(ans,num);
		return;
	}
	if (x<=0) return;
	if (num>=ans) return;
	if (sum+qjl[x]<chao.size()) return;//一定有遗漏 
	vector<int> yzf;
	for (int i=0;i<ls[x].size();++i)
	{
		if (!vis[ls[x][i]])
		{
			yzf.push_back(ls[x][i]);
			vis[ls[x][i]]=true;
		}
	}
	dfs(x-1,sum+yzf.size(),num+1);
	for (int i=0;i<yzf.size();++i) vis[yzf[i]]=false;
	yzf.clear();
	dfs(x-1,sum,num);
}
void work0()
{
	for (i=1;i<=n;++i)
	{
		che=false;
		if (ca[i].a==0)//匀速 
		{
			if (ca[i].v<=V) continue;
			for (j=m;j;--j)
			{
				if (mo[j]<ca[i].d) break;
				ls[j].push_back(i);
				if (!che) cnt++,chao.push_back(i),che=true;
			}
		}
		else if (ca[i].a>0)//匀加速 
		{
			if (ca[i].v>V)
			{
				for (j=m;j;--j)
				{
					if (mo[j]<ca[i].d) break;
					ls[j].push_back(i);
					if (!che) cnt++,chao.push_back(i),che=true;
				}
			}
			else
			{
				d1=ca[i].d+(double)((V+ca[i].v)*(V-ca[i].v)/(2*ca[i].a));
				for (j=m;j;--j)
				{
					if (mo[j]<=d1) break;
					ls[j].push_back(i);
					if (!che) cnt++,chao.push_back(i),che=true;
				}
			}
		}
		else//匀减速 
		{
			if (ca[i].v<=V) continue;
			d1=ca[i].d+(double)((V+ca[i].v)*(ca[i].v-V)/(-2*ca[i].a));
			for (j=1;j<=m;++j)
			{
				if (mo[j]<ca[i].d) continue;
				if (mo[j]>=d1) break;
				ls[j].push_back(i);
				if (!che) cnt++,chao.push_back(i),che=true;
			}
		}
	}
	cout<<cnt<<' ';
	for (i=1;i<=m;++i) qjl[i]=qjl[i-1]+ls[i].size();
	dfs(m,0,0);
	cout<<m-ans<<endl;
}
void work1()//匀速 
{
	for (i=1;i<=n;++i)
	{
		if (ca[i].v<=V||ca[i].d>mo[m]) continue;
		cnt++;
	}
	if (cnt==0) cout<<0<<' '<<m<<endl;
	else cout<<cnt<<' '<<m-1<<endl;
}
void work2()//匀加速 
{
	for (i=1;i<=n;++i)
	{
		d1=ca[i].d;
		if (ca[i].v<=V)
		{
			d1+=(double)((V+ca[i].v)*(V-ca[i].v)/(2*ca[i].a));
			if (mo[m]>d1) cnt++;
		} 
		else if (mo[m]>=d1) cnt++;
	}
	if (cnt==0) cout<<0<<' '<<m<<endl;
	else cout<<cnt<<' '<<m-1<<endl;
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout); 
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>L>>V;
		memset(ca,0,sizeof(ca)),memset(mo,0,sizeof(mo));memset(qjl,0,sizeof(qjl));memset(vis,false,sizeof(vis));
		chao.clear();
		wa=wb=wc=true;cnt=0;ans=1e5+5;
		for (i=1;i<=n;++i)
		{
			cin>>ca[i].d>>ca[i].v>>ca[i].a;
			if (ca[i].a>0) wa=wc=false;
			else if (ca[i].a==0) wb=wc=false;
			else wa=wb=false;
		} 
		for (i=1;i<=m;++i) cin>>mo[i],ls[i].clear();
		if (n<=20&&m<=20) work0();
		else if (wa) work1();
		else if (wb) work2();
		else work0();
	}
	return 0;
}
