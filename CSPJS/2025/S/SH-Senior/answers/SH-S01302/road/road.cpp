#include <iostream>
#include <fstream>
#include <queue>
#define EIN fin
#define EOUT fout
using namespace std;
ifstream fin("road.in");
ofstream fout("road.out");
const long long clln=1e4+15,cllm=1e6+1e5+5;
long long lfirst[clln],lnext[cllm*2],lgo[cllm*2],lval[cllm*2],lt=0;
bool tf[clln];
priority_queue <pair<long long ,long long > > q; 

void funcedge(long long x,long long y,long long z)
{
	lnext[++lt]=lfirst[x];
	lfirst[x]=lt;
	lgo[lt]=y;
	lval[lt]=z;
}

void funcc1(long long n)
{
	tf[1]=1;
	for(long long a=lfirst[1];a;a=lnext[a])
		q.push({-lval[a],lgo[a]});
	long long an=0,t=1;
	while(q.size())
	{
		long long x=q.top().second,y=-q.top().first;
		q.pop();
		if(tf[x]) continue;
		tf[x]=1;
		an+=y;
		t++;
		if(t==n) break;
		for(long long e=lfirst[x];e;e=lnext[e])
			if(!tf[lgo[e]])
				q.push({-lval[e],lgo[e]}); 
	}
	EOUT<<an<<'\n';
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n,m,k; EIN>>n>>m>>k;
	for(long long a=1;a<=m;a++)
	{
		long long x,y,z; EIN>>x>>y>>z;
		funcedge(x,y,z);
		funcedge(y,x,z);
	}
	for(long long a=1;a<=k;a++)
	{
		long long x; EIN>>x;
		for(long long b=1;b<=n;b++)
		{
			EIN>>x;
			funcedge(n+a,b,x);
			funcedge(b,n+a,x);
		}
	}
	funcc1(n+k);
	fin.close();
	fout.close();
	return 0;
}
