#include<bits/stdc++.h>
using namespace std;
vector<int> a;
int b=0;
long long ans=0;
void dfs(int l,int s,int o)
{
	if(s>a[l]*2&&o>=3)
	{
		ans++;
		ans%=998244353;
	}
	for(int i=l+1;i<b;i++)
	{
		dfs(i,s+a[i],o+1);
	}
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>b;
	int asd;
	for(int i=0;i<b;i++)
	{
		cin>>asd;
		a.push_back(asd);
	}
	sort(a.begin(),a.end());
	dfs(-1,0,0);
	cout<<ans;
	return 0;
}
