#include <bits/stdc++.h>
using namespace std;
const int N=500005;
int a[N],sum[N];
set<int> s;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0,pre=0;
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	s.insert(0);
	for(int i=1;i<=n;i++)
	{
		sum[i]=pre^a[i];
		if(s.count(sum[i]^k))
		{
			ans++;
			pre=0;
			s.clear();
			s.insert(0);
		}
		else
		{
			s.insert(sum[i]);
			pre=sum[i];
		}
	}
	cout<<ans;
	return 0;
}
