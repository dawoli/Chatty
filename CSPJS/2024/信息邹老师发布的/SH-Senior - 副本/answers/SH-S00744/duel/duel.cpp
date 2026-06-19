#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define N 100005
using namespace std;

int n;
int a[N];
int m;

signed main() {
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i)
	{
		int x;
		scanf("%d",&x);
		m=max(x,m);
		a[x]++;
	}
	int ans = 0;
	int l = 1;
	for (int i = 2; i <=m; ++i)
	{
		int j=a[i];
		while (j>0 and l<i){
			if (j>=a[l])
			{
				j-=a[l];
				a[l]=0;
				l++;
			}else {
				a[l]-=j;
				j=0;
			}
		}
	}
	for (int i = l; i <= m ; ++i)
	{
		ans+=a[i];
	}
	printf("%d\n",ans);

}
