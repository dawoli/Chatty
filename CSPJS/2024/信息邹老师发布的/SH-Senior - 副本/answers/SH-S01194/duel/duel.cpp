#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n;
int a[maxn];
int main()
{
//	freopen("duel4.in","r",stdin);
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)	scanf("%d",&a[i]);
	sort (a+1,a+n+1);
	
	int ans=1;
	for (int i=1;i<=n;i++)
		if (ans<i&&a[i]>a[ans])	ans++;
	ans--;
	printf("%d",n-ans);
	return 0;
}
