#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[105],cnt,ans1,ans2;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	scanf("%lld",&a[1]);
	for(int i=2;i<=m*n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]>a[1]) cnt++;
	}
	cnt++;
	if(cnt%n==0) ans1=cnt/n;
	else ans1=cnt/n+1;
	ans2=cnt-(ans1-1)*n;
	if(ans1%2==0) ans2=n-ans2+1;
	printf("%lld %lld",ans1,ans2);
	return 0;
} 
