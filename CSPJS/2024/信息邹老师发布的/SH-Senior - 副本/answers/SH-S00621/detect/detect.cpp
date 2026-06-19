#include <vector>
#include <fstream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

ifstream fin("detect.in");
ofstream fout("detect.out");

struct vehicle
{
	int d,v,a;
	bool overspeed=false;

	vehicle()
	{
		d=v=a=0;
	}

	vehicle(int d,int v,int a)
	{
		this->d=d;
		this->v=v;
		this->a=a;
	}

	int speed2(int p)
	{
		if(p<d)
		{
			return 0;
		}
		int dis=p-d;
		double v2p = v*v+2*a*dis;
		if(v2p<=0)
		{
			return 0;
		}
		return v2p;
	}
};

int dfs(int m, int i,int x,vector<vehicle>&veh,int p[],int ans,int V)
{
	if(i>m)
	{
		int cnt=0;
		for(auto &v:veh)
		{
			cnt = cnt + v.overspeed;
		}
		if(cnt == ans)
		{
			return x;
		}
		else
		{
			return 1000000;
		}
	}
	vector<vehicle>veh1=veh;
	auto re = dfs(m,i+1,x,veh1,p,ans,V);
	for(auto &v:veh)
	{
		if(!v.overspeed)
		{
			if(v.speed2(p[i])>V)
			{
				v.overspeed=true;
			}
		}
	}
	return min(re,dfs(m,i+1,x+1,veh,p,ans,V));
}

void solve()
{
	int n,m,L,V;
	fin>>n>>m>>L>>V;
	vector<vehicle>veh;
	int p[100005];
	
	bool spA=true,spB=true,spC=true;
	
	for(int i=1; i<=n; i++)
	{
		int d,v,a;
		fin>>d>>v>>a;
		veh.emplace_back(d,v,a);
		spA=spA&&(a==0);
		spB=spB&&(a>0);
		spC=spC&&(a<0);
	}
	
	V=V*V;
	
	if(spA||spB)
	{
		int ans = 0,ans1;
		int maxp=-1;
		int maxd=-1;
		for(int i=1; i<=m; i++)
		{
			int p;
			fin>>p;
			maxp=max(maxp,p);
		}
		for(auto &v:veh)
		{
			maxd=max(maxd,v.d);
			if(v.speed2(maxp)>V)
			{
				ans++;
			}
		}
		ans1=m-1;
		if(ans==0)
		{
			ans1=m;
		}
		fout<<ans<<" "<<ans1<<endl;
		return;
	}
	
	vector<vehicle>veh1=veh;
	for(int i=1; i<=m; i++)
	{
		fin>>p[i];
		for(auto &v:veh1)
		{
			if(!v.overspeed)
			{
				if(v.speed2(p[i])>V)
				{
					v.overspeed=true;
				}
			}
		}
	}
	int ans=0,ans1=m;
	for(auto &v:veh1)
	{
		ans = ans + v.overspeed;
	}

	if(n<=20&&m<=20)
	{
		ans1 = m - dfs(m,1,0,veh,p,ans,V);
	}

	fout<<ans<<" "<<ans1<<endl;
}

int main()
{
	int T;
	fin>>T;
	for(int i=1; i<=T; i++)
	{
		solve();
	}
}
