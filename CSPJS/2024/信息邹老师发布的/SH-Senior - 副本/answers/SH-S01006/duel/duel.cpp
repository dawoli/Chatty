#include <bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	int cnt=0;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		if (a[i]==1)	cnt++;
	}
	cout<<max(cnt,n-cnt)<<endl;
	return 0;
}

