#include <bits/stdc++.h>
#define lol long long
using namespace std;

struct node
{
	int v;
	int co;
	int pe;
	int tr;
};

bool cmp(node x,node y)
{
	return x.v > y.v;
}

bool cmp2(int x,int y)
{
	return x > y;
}

//int a[100005][5];

vector<node> a;

bool vis[100005];

bool flag = 1;
//
//bool cmp(node x,node y)
//{
//	return x.tr < y.tr;
//}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int t;
	cin>>t;
	
	while(t --)
	{
		vector<int> s;
		lol ans = 0;
		memset(vis,0,sizeof(vis));
		a.clear();
		
		//w[i] = 1;
		//v[i] = a[i][k] 
		int ju[5];
		memset(ju,0,sizeof(ju));
		memset(vis,0,sizeof(vis));
		
		int a1=0 , b1=0, c1=0; 
		
		int n;
		cin>>n;
		for(int i = 1;i <= n;i ++)
		{
			for(int j = 1;j <= 3;j ++)
			{
				int va;
				cin>>va;
				if(j == 1)
				{
					s.push_back(va);
				}
				if(j != 1 && va != 0) flag = 0;
				a.push_back({va,j,i});
			}
		}
		
		if(flag)
		{
			for(auto & g : s)
			{
				cout<<g<<'\n';
			}
			
			sort(s.begin(),s.end());
			
			for(auto & g : s)
			{
				cout<<g<<'\n';
			}
			
			int sum = 0;
			int tsg = n / 2;
			while(tsg --)
			{
				int mm = s.back();
				s.pop_back();
				sum += mm; 
			 } 
			cout<<sum<<'\n';
			continue;
		}
			
		sort(a.begin(),a.begin() + a.size() + 1,cmp);
		
		//a.pop_back();
		
//		for(auto & x : a)
//		{
//			cout<<x.v<<' ';
//		}
//		
		for(auto & f : a)
		{
			//cout<<ju[f.co]<<'\n';
			if(ju[f.co] >= n / 2) continue;
			
			if(vis[f.pe]) continue;
			
			ju[f.co] ++; 
			vis[f.pe] = 1;
			ans += f.v;
		}
		cout<<ans<<'\n';
	}
	
	
	
	return 0;
}
