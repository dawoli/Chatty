#include<bits/stdc++.h>
using namespace std;
int n,a[100005],ans;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	ans=n;
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		int k=i-1;
		while((a[k]==0)||(a[k]==a[i]))
		{
			k--;
		}
		if(k>0)
		{
			a[k]=0;
			ans--;
		}
	}
	cout<<ans;
	return 0;
}
