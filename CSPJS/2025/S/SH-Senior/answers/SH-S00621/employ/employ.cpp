#include<bits/stdc++.h>
using namespace std;
long long ans=1;
int n,m;
string s;
int c[501]={0};
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
		ans=ans*i%998244353;
	}
	printf("%lld",ans);
	return 0;
}
