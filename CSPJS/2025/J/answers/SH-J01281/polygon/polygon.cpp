#include <bits/stdc++.h>
using namespace std;
int ans=0,n;
int arr[100010],vis[100010];
class ProvedSolution
{
	int maxn(vector<int> v)
	{
		int maxx=INT_MIN;
		for(int i:v) maxx=max(maxx,i);
		return maxx;
	}
	int sumn(vector<int> v)
	{
		int sumx=0;
		for(int i:v) sumx+=i;
		return sumx;
	}
	public:
	void dfs(vector<int> choice)
	{
		if(choice.size()>=3&&2*maxn(choice)<=sumn(choice)) {ans++,ans%=998'244'353;}
		if(choice.size()>n) return;
		for(int i=1;i<=n;i++)
		{
			//for(int i:choice) cout<<i;cout<<endl;
			if(vis[i]) continue;
			vis[i]=1;
			choice.push_back(arr[i]);
			dfs(choice);
			// choice.pop_back();
			// vis[i]=0;
		}
	}
	void mainentry()
	{
		dfs({});
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
	cin>>n;
	for(int i=1;i<=n;i++) cin>>arr[i];
	ProvedSolution().mainentry();
	cout<<ans;
}
int main()
{
	#define singletest
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	#ifdef singletest
	solve();
	#else
	int n;
	cin>>n;
	while(n--) solve();
	#endif
	return 0;
}
