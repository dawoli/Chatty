#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+105,M=1.5e6+8; 
//²¢²é¼¯£¡ 
struct node
{
	ll u,v,w;
	bool operator <(const node &rhs) const
	{
		return w>rhs.w;
	}
}rep;
priority_queue <node> pq;

struct node1
{
	ll u,v,w;
	bool operator <(const node1 &rhs) const
	{
		return w<rhs.w;
	}
}newr[M],newb;
vector <node> mpa[N];

ll n,m,k,fa[N],cost[N],temp,cnt=0,ans=0,rec=0,extra[N];
ll lock[N];

ll findf(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=findf(fa[x]);
}

void merge(int x,int y)
{
	fa[x]=findf(y);
}

bool cmp(int a,int b)
{
	return fa[a]==fa[b];
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0);
	cin>>n>>m>>k;
	
	memset(lock,0,sizeof lock);
	
	for(int i=0;i<=n+k+1;i++) fa[i]=i;
	
	for(int i=1,u,v,w;i<=m;i++)
	{
		cin>>u>>v>>w;
		pq.push({u,v,w});
	}

	for(int i=1+n;i<=k+n;i++)
	{
		cin>>cost[i];
		for(int j=1;j<=n;j++) 
		{
			cin>>temp;
			newr[cnt++]={i,j,temp};
			mpa[i].push_back({i,j,temp});
		}
	}
	sort(newr,newr+cnt);
	int nown=n,idx=0;
	
	/*for(int i=0;i<cnt;i++)
	{
		cout<<newr[i].u<<" "<<newr[i].v<<" "<<newr[i].w<<endl;
	}*/
	
	while(rec<nown-1)
	{
		while(!pq.empty())
		{
			rep=pq.top();
			if(!cmp(rep.u,rep.v)) break;
			pq.pop();
		}
		for(;idx<cnt;idx++)
		{
			if(cmp(newr[idx].u,newr[idx].v)==1||lock[newr[idx].u]>0) continue;
			else break;
		}
		
		//cout<<cost[newr[idx].u]+newr[idx].w<<"&"<<rep.w<<endl;
		
		if(idx<cnt&&lock[newr[idx].u]==0&&cost[newr[idx].u]+newr[idx].w<=rep.w)
		{
			//cout<<"create1:"<<newr[idx].u<<" "<<newr[idx].v<<endl; 
			nown++;
			merge(newr[idx].u,newr[idx].v);
			ans+=(cost[newr[idx].u]+newr[idx].w);
			lock[newr[idx].u]++;
			lock[newr[idx].v]++;
			extra[newr[idx].u]=cost[newr[idx].u]+newr[idx].w;
			for(int i=0;i<mpa[newr[idx].u].size();i++)
			{
				pq.push(mpa[newr[idx].u][i]);
			}
		}
		else if(idx<cnt&&lock[newr[idx].u]!=0&&cost[newr[idx].u]+newr[idx].w<=rep.w)
		{
			//cout<<"merge1:"<<newr[idx].u<<" "<<newr[idx].v<<endl; 
			merge(newr[idx].u,newr[idx].v);
			ans+=(newr[idx].w);
			lock[newr[idx].u]++;
			lock[newr[idx].v]++;
		}
		else
		{
			//cout<<"merge2:"<<rep.u<<" "<<rep.v<<endl;
			ans+=rep.w;
			merge(rep.u,rep.v);
			lock[rep.u]++;
			lock[rep.v]++;
		}
		/*for(int i=1;i<=n+k;i++) cout<<fa[i]<<" ";
		cout<<endl;
		for(int i=1;i<=n+k;i++) cout<<lock[i]<<" ";
		cout<<endl;
		for(int i=1;i<=n+k;i++) cout<<cost[i]<<" ";
		cout<<endl<<ans<<endl<<endl;*/
		rec++;
	}
	/*for(int i=1;i<=n+k;i++) cout<<lock[i]<<" ";
	cout<<endl;*/
	for(int i=n+1;i<=n+k;i++)
	{
		if(lock[i]==1)
		{
			ans-=extra[i];
		}
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
