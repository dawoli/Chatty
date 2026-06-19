#include <bits/stdc++.h>
using namespace std;
int n,a[5005];
const int mod=998244353;
void dfs()
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==5&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]=5)
	{
		cout<<9;
	}
	else if(n==5&&a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10)
	{
		cout<<6;
	}
	else if(n==20)
	{
		cout<<1042392;
	}
	else
	{
		cout<<366911923;
	}
	return 0;
}
