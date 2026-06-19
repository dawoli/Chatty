#include<bits/stdc++.h>
using namespace std;
namespace Soaring_Wings
{
struct Car
{
	double d,v,a;
	double time_to_speed(int t)const
	{
		return v+a*t;
	};
	double time_to_dis(int t)const
	{
		return v*t+0.5*a*t*t;	
	};
	double dis_to_speed(int s)const
	{
		return sqrt(v*v+2.0*a*s);	
	};
	double speed_to_dis(int v1)const
	{
		return (v1-v)/2*a*1.0;
	};
};	
struct Section
{
	int x,y,n;
	Section()=default;
	Section(const int a, const int b):
		x(a),y(b){}
	Section(const int &a, const int &b,const int &car):
		x(a),y(b),n(car){}
};
bool operator<(const Section &a,const Section &b)
{
	if(a.x==b.x)return a.y<b.y;
	else return a.x<b.x;
};
int T,n,m,L,V,ans=0,close=0;
bool flag;
vector<Car> car;
vector<int> p;
vector<Section> sec;
void Soar()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--)
	{
		ans=0;
		sec.clear();
		cin>>n>>m>>L>>V;
		car.resize(n+1);
		p.resize(m+1);
		sec.push_back(Section(0,0,0));
		car[1].d=-1;
		for(int i=1;i<=n;i++)
			cin>>car[i].d>>car[i].v>>car[i].a;
		for(int i=1;i<=m;i++)cin>>p[i];
		sort(p.begin()+1,p.end());
		for(int i=1;i<=n;i++)
		{
			if(car[i].d==-1)continue;
			flag=0;
			if(car[i].a==0)
			{
				if(car[i].v>V)
				{
					auto lb=lower_bound(p.begin(),p.end(),car[i].d);
					if(lb!=p.end())
					{
						sec.push_back(Section(*lb,p[m],i));
					}
				}
				continue;
			}
			else if(car[i].v>V&&car[i].a<0)
			{
				int dis=car[i].speed_to_dis(V);
				auto l=lower_bound(p.begin(),p.end(),car[i].d);
				auto r=lower_bound(p.begin(),p.end(),dis)-1;
				if(l!=p.end())
				{
					sec.push_back(Section(*l,*r,i));
				}
				continue;
			}
			for(auto j:p)
			{
				if(j<car[i].d)continue;
				if(car[i].dis_to_speed(j)<=0)break;
				if(car[i].dis_to_speed(j)>V)
				{
					if(car[i].a>=0)
					{
						sec.push_back(Section(j,p[m],i));
						ans++;
						break;
					}
					else 
					{
						if(flag==1)continue;
						sec.push_back(Section(j,0,i));
						flag=1;
						ans++;
					}
				}
				else if(flag)
				{
					sec[sec.size()-1].y=j;
					break;
				}
			}
		}
		sort(++sec.begin(),sec.end());
		for(auto now:sec)
		{
			cout<<'#'<<now.x<<' '<<now.y<<' '<<now.n<<endl;
		}
		auto index=p.begin(),last=p.begin();
		for(auto i:sec)
		{
			if(i.x<=*index&&*index<=i.y)continue;
			else 
			{
				last=index;
				index=upper_bound(p.begin()+1,p.end(),i.y)-1;
				close+=index-last;
			}
		}
		cout<<ans<<' '<<close<<endl;
		return ;	
	}
}
}
int main()
{
	Soaring_Wings::Soar();
	return 0;
}
