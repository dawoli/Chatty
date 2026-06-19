#include<iostream>
#include<map>
using namespace std;
int a[200002];
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t; cin>>t;
	while (t--)
	{
		map<int,int> mp;
		long long ans=0;
		int n; cin>>n;
		for (int i=0;i<n;i++)
		{
			cin>>a[i];
			mp[a[i]]++;
		}
		map<int,int> vis;
		for (int i=0;i<n;i++)
		{
			if (!vis[a[i]]) ans+=a[i]*(mp[a[i]]-1);
			vis[a[i]]=1; 
		}
		cout<<ans<<endl;
	}
	return 0;
 } 
