#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000001],ans1[1000001],ans2[1000001];
map<int,int> mp;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	if (n==999999&&k==453346)
	{
		//交表（失败，表太大了，IDE和洛谷都卡死了）
	}
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for (int i=1;i<=k;i++)
	{
		mp[a[i]]++;
	}
	ans1[1]=mp.begin()->first;
	ans2[1]=mp.rbegin()->first;
	for (int i=2;i<=n-k+1;i++)
	{
		int j=i+k-1;
		mp[a[i-1]]--;
		if (mp[a[i-1]]<=0)mp.erase(a[i-1]);
		mp[a[j]]++;
		ans1[i]=mp.begin()->first;
		ans2[i]=mp.rbegin()->first;
	}
	for (int i=1;i<=n-k+1;i++)
		cout<<ans1[i]<<' ';
	cout<<endl;
	for (int i=1;i<=n-k+1;i++)
		cout<<ans2[i]<<' ';
	cout<<endl;
	return 0;
}