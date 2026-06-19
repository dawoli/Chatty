#include <bits/stdc++.h>
using namespace std;
int ans=0,n,m;
int arr[500010];
vector<pair<int,int> > res;
#define singletest
class ProvedSolution
{
	public:
	int mainentry()
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				int xorv=arr[i];
				for(int k=i+1;k<=j;k++) xorv^=arr[k];
				if(xorv==m)
				{
					cout<<i<<j<<xorv<<endl;
					ans++;
					res.push_back({i,j});
					break;
				}
				else cout<<i<<j<<xorv<<endl;
			}
		}
		cout<<ans;
		int repeated=0;
		for(int i=0;i<res.size();i++)
		{
			for(int j=i+1;j<res.size();j++)
			{
				if(res[i].second>=res[j].first) repeated++,cout<<res[i].first<<res[i].second<<res[j].first<<res[j].second<<endl;
				else ans-=ceil(1.0*repeated/2),repeated=0;
			}
			if(repeated) ans-=ceil(1.0*repeated/2),repeated=0;
		}
		if(repeated) ans-=ceil(1.0*repeated/2),repeated=0;
		return ans;
	}
};
class Solution
{
	public:
	void mainentry()
	{
		
	}
};

void init()
{
	
}
void solve()
{
	init();
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>arr[i];
	cout<<ProvedSolution().mainentry();
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	#ifdef singletest
	solve();
	#else
	int n;
	cin>>n;
	while(n--) solve();
	#endif
	return 0;
}

// 大样例都没过...不指望 AC 了
