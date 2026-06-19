#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+5;
bool flag1 , flag2;

int n , m , k , a[N] , c[N] , b[N] ,d[N], e[N] , q , w , t , sum;
signed main()
{
	freopen("package.in","r",stdin);
	freopen("package.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	flag1=flag2=1;
	if(k!=0) flag2 = 0;
	for(int i = 1 ; i<=m ; i++) cin>>a[i];
	for(int i = 1 ; i<=n+2 ; i++)
	{
		cin>>b[i]>>c[i];
		if(b[i]!=1) flag1 = 0;
		d[i] = c[i];
	}
	if(flag2==1)
	{
			if(flag1==1)
			{
				for(int i = 1 ; i<=n ; i++)
				{
					sum+=c[i];
					sum = a[sum];
				}
				cout<<sum;
			}
	}
	return 0;
}
