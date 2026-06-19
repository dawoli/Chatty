//sort
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,i,j,a[maxn],cnt,l,r;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	memset(a,0,sizeof(a));
	for (i=1;i<=n;++i) scanf("%d",&a[i]);
	if (n==1) {cout<<1<<endl; return 0;}//льеп 
	sort(a+1,a+n+1);
	l=1,r=2;
	while (r<=n)
	{
		if (a[l]==a[r])
		{
			r++;
			continue;
		} 
		l++,cnt++,r++;
	}
	cout<<n-cnt<<endl;
	return 0;
}
