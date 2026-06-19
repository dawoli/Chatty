#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,a[105],R,c=1,r=1;
bool down=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n*m;i++) scanf("%d",&a[i]);
	R=a[1];
	sort(a+1,a+n*m+1);
	for (int i=n*m;i>=1;i--)
	{
		if (a[i]==R) break;
		if (down)
		{
			if (r==n)
			{
				c++;
				down=0;
			}
			else r++;
		}
		else
		{
			if (r==1)
			{
				c++;
				down=1;
			}
			else r--;
		}
	}
	printf("%d %d",c,r);
	return 0;
}
