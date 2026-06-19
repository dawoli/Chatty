#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int n,t;
	cin>>t;
	int s;
	for(int i=1;i<=t;i++)
	{	
		int a[100005] = {};
		cin>>n;
		int maxn = 0;
		int ans = 0;
		for(int j=1;j<=n;j++)
		{
			cin>>s;
			maxn = max(maxn,s);
			a[s]++;
		}
		for(int j=1;j<=maxn;j++)
		{
			if(a[j]==0) continue;
			ans+=(a[j]-1)*j;
		}
		cout<<ans;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
