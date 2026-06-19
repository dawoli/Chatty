#include<bits/stdc++.h>
using namespace std;

struct Node{
	int x,y,z;
};


bool cmpx(const Node &s1,const Node &s2)
{
	return (s1.x-max(s1.y,s1.z)) < (s2.x-max(s2.y,s2.z));
}

bool cmpy(const Node &s1,const Node &s2)
{
	return (s1.y-max(s1.x,s1.z)) < (s2.y-max(s2.x,s2.z));
}

bool cmpz(const Node &s1,const Node &s2)
{
	return (s1.z-max(s1.y,s1.x)) < (s2.z-max(s2.y,s2.x));
}


int n,T,ans;
Node a[114514];
vector<Node> groupx;
vector<Node> groupy;
vector<Node> groupz;
int cntx,cnty,cntz;

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		groupx.clear();
		groupy.clear();
		groupz.clear();
		ans = 0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i].x >= a[i].y && a[i].x >= a[i].z)
			{
				groupx.push_back(a[i]);
				ans += a[i].x;
			}else if(a[i].y >= a[i].x && a[i].y >= a[i].z)
			{
				groupy.push_back(a[i]);
				ans += a[i].y;
			}else
			{
				groupz.push_back(a[i]);
				ans += a[i].z;			
			}
		}
		cntx = groupx.size();
		cnty = groupy.size();
		cntz = groupz.size();
		if(cntx > n/2)
		{
			sort(groupx.begin(),groupx.end(),cmpx);
			for(int i=0;i<cntx-n/2;i++)
			ans -= groupx[i].x-max(groupx[i].y,groupx[i].z);
		}else if(cnty > n/2)
		{
			sort(groupy.begin(),groupy.end(),cmpy);
			for(int i=0;i<cnty-n/2;i++)
			ans -= groupy[i].y-max(groupy[i].x,groupy[i].z);
		}else if(cntz > n/2)
		{
			sort(groupz.begin(),groupz.end(),cmpz);
			for(int i=0;i<cntz-n/2;i++)
			ans -= groupz[i].z-max(groupz[i].y,groupz[i].x);
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}
