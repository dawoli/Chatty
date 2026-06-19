#include<bits/stdc++.h>
using namespace std;
namespace Soaring_Wings
{
	int T,n;
	void Soar()
	{
		ios::sync_with_stdio(false);
		cin.tie(0);
		cout.tie(0);
		cin>>n;
		vector<int> a(n+1,0),f(n+1,0);
	    unordered_map<int,int> lst;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(lst.find(a[i])==lst.end())
			{
				lst[a[i]]=i;
			}
		}
		f[0]=0,f[1]=0;
		for(int i=2;i<=n;i++)
		{
			if(lst[a[i]]!=i&&a[lst[a[i]]]==a[i]&&f[i-1]<f[i-1]+a[i])
			{
				f[i]=f[i-1]+a[i];
				lst[a[i]]=i;
			}
			else f[i]=f[i-1];
			//cout<<f[i]<<endl;
		}
		cout<<f[n]<<endl;
		//cout<<lst[2];
	}
	void solve()
	{
		cin>>T;
		while(T--)
		{
			Soar();
		}
	}
}
int main()
{
	Soaring_Wings::solve();
	return 0;
}