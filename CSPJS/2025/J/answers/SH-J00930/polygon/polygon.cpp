#include<bits/stdc++.h>
using namespace std;
int n,a[5020];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int ans=0;
	int q=a[1],w=a[2],e=a[3];
	if(q+w+e>2*max(max(q,w),e)) cout<<1;
	else cout<<0;
	return 0;
}
