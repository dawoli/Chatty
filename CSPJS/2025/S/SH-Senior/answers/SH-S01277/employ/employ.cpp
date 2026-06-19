#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long p(int n)
{
	long long s=1;
	while(n)
	{
		s=s*n%mod;
		n--;
	}
	return s;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	printf("%lld",p(n));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
