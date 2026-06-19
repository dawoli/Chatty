#include <cstdio>
#include <algorithm>
using namespace std;
int T,n;
struct member
{
	int x1,x2,x3;
}a[100005];
bool T12;
bool cmp12(member X1,member X2)
{
	return X1.x1<X2.x1;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	for (int Q=0;Q<T;Q++)
	{
		T12=1;
		scanf("%d",&n);
		for (int i=0;i<n;i++)
		{
			scanf("%d%d%d",&a[i].x1,&a[i].x2,&a[i].x3);
			if (a[i].x2!=0||a[i].x3!=0) T12=0;
		}
		if (T12)
		{
			int answer=0;
			sort(a,a+n,cmp12);
			for (int i=n-1;i>=n/2;i--) answer+=a[i].x1;
			printf("%d\n",answer);
			continue;
		}
	}
	return 0;
}
