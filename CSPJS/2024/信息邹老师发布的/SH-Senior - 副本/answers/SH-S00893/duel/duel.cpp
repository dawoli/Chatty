#include<bits/stdc++.h>
using namespace std;
long long n,a[100009],ans=0;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long b;
		cin>>b;
		a[b]++;
		ans=max(a[b],ans);
	}
	cout<<ans<<endl;
}
