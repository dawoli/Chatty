#include<bits/stdc++.h>
#define N 100009
#define M 1000009
#define ll long long
#define mp make_pair
using namespace std;

int T,n,m,L,V;
int ans1,ans2,now;
int d[N],v[N],a[N];
int p[N],cnt_car[N];
int bit[M];
//bool is_m[M];
vector<vector<pair<double,double> > >pts; //pts[r]=(l1,i1) (l2,i2)

void clear()
{
	ans1=n;
	ans2=0;
	now=0;
	pts.clear();
	pts.resize(L+1);
	for(int i=0;i<=n+1;i++)cnt_car[i]=0;
	for(int i=0;i<=L+1;i++)bit[i]=0;
}

int LSB(int x){ return x&(-x); }

void add(int x)
{
	while(x<=L+1)
	{
		++bit[x];
		x+=LSB(x);
	}
}

int psq(int x)
{
	int anss=0;
	while(x)
	{
		anss+=bit[x];
		x-=LSB(x);
	}
	return anss;
}

void input()
{
	for(int i=1;i<=n;i++)
	{
		cin>>d[i]>>v[i]>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>p[i];
		//is_m[p[i]]=true;
	}
	sort(p+1,p+1+m);
	L=p[m];
}

void solve()
{
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0)
		{
			if(v[i]>V)
			{
				//cout<<i<<" "<<"CHAO SU"<<endl;
				pts[L].emplace_back( mp(d[i],i) );
				continue;
			}
		}
		else if(a[i]<0)
		{
			if(v[i]>V)
			{
				//找什么时候不超速
				int fast_pt=(V*V-v[i]*v[i])/a[i]/2;
				double more=(double)(V*V-v[i]*v[i])/a[i]/2;
				//cout<<more<<endl;
				if(more-fast_pt==0)fast_pt--; //到fast_pt刚好最后超速 
				pts[min(L,d[i]+fast_pt)].emplace_back( mp(d[i],i) );
				continue; 
			}
		}
		else
		{
			if(v[i]>V)
			{
				pts[L].emplace_back( mp(d[i],i) );
				continue;
			}
			int fast_pt=(V*V-v[i]*v[i])/a[i]/2;
			double more=(double)(V*V-v[i]*v[i])/a[i]/2;
			if(more-fast_pt==0)fast_pt++; //到fast_pt刚好最后超速 
			
			if(d[i]+fast_pt<=L) //在L以内超速 
			{
				pts[L].emplace_back( mp(d[i]+fast_pt,i) );
				continue; 
			}
		}
		
		//过滤掉不超速车辆 
		//cout<<"None"<<" "<<i<<endl;
		ans1--;
	}
	//cout<<ans1<<endl;
	p[0]=0;
	p[m+1]=L+1;
	cnt_car[m+1]=0;
	int r=L+1;
	for(int i=m;i>=1;i--)
	{
		cnt_car[i]=psq(p[i]);//这个探头探到右边的车辆 
		
		for(;r>=p[i];r--)
		for(auto j:pts[r])
		{
			//cout<<j.second<<" "<<j.first<<" "<<r<<endl;
			add(j.first);
			now++;
		}
		int psqR=psq(p[i]);
		
		cnt_car[i-1]=psq(p[i-1]);
		int un_notice=now-(psqR-cnt_car[i]);
		//cout<<un_notice<<endl;
		ans1-=un_notice; //没有被探到的数量 
		if(un_notice==now)ans2++; //探到的没有新车 
		cnt_car[i]=psqR;
		now=0;
	}
	
	//没探头 
	for(;r>=0;r--)
	for(auto j:pts[r])
	{
		//cout<<j.second<<" "<<j.first<<" "<<r<<endl;
		add(j.first);
		ans1--;
		ans2++;
	}
	
	cout<<ans1<<" "<<ans2<<endl; 
}

int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>L>>V;
		clear();
		input();
		solve();
	}
	return 0;
} 
