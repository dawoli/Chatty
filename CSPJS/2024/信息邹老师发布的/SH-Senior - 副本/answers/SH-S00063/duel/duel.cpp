#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[101010],type,t[101010],ans;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	a[0]=-1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=a[i-1]) type++;
		t[type]++;
	}
	int spare=t[1];
	for(int i=2;i<=type;i++)
	{
		int ans0=min(spare,t[i]);
		ans+=ans0;
		spare-=ans0;
		spare+=t[i];
	}
	cout<<n-ans;
	return 0;
}

