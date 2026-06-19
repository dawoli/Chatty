#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
using namespace std;

int T;
int n,k,Q;
int r,c;
bool ans=false;
vector< vector<pair<int,int> > >geto; //geto[×ó][1 ~ nR] ÓÒ ÈË 
vector< vector<int> >s;
struct point{
	int now,turn,who;
};

void clear()
{
	geto.clear();
	geto.resize(200009);
	s.resize(n+1);
}

void input()
{
	int len;
	for(int numS=1;numS<=n;numS++)
	{
		cin>>len;
		s[numS].resize(len+1);
		for(int j=1;j<=len;j++)
		{
			cin>>s[numS][j];
			for(int i=max(j-k+1,1);i<j;i++)
			{
				if(find( geto[ s[numS][i] ].begin() , geto[ s[numS][i] ].end() , mp(s[numS][j],numS) )==geto[ s[numS][i] ].end()) 
				geto[ s[numS][i] ].emplace_back( mp(s[numS][j],numS) );
			}
		}
	}
}

void go()
{
	queue< point >q; // <now,who> / turn
	q.push( point{1,0,0} );
	while(!q.empty())
	{
		point pt=q.front();
		q.pop();
		if(pt.turn>r)continue;
		if(pt.turn==r&&pt.now==c)
		{
			ans=true;
			break;
		}
		for(auto j:geto[pt.now])
		{
			if(j.second==pt.who)continue;
			q.push((point){j.first,pt.turn+1,j.second});
		}
	}
}

void r1go()
{
	for(auto j:geto[1])
	{
		if(j.first==c)			
		{
			ans=true;
			break;
		}
	}
	return ;
}

void solve()
{
	for(int nq=1;nq<=Q;nq++)
	{
		cin>>r>>c;
		ans=false;
		if(r==1)r1go();
		else go();
		if(ans)cout<<"1\n";
		else cout<<"0\n";
	}
}

int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n>>k>>Q;
		clear();
		input();
		solve();
	}
	//cout<<endl;
	return 0;
}
