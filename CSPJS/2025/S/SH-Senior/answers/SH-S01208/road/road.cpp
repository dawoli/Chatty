#include <bits/stdc++.h>
using namespace std;
int main()
{
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
    int a[109][3],i=1;
    cin >>a[i][0]>>a[i][1]>>a[i][2];
	        int maxn=max(a[i][0],max(a[i][1],a[i][2]));
	        int minn=min(a[i][0],min(a[i][1],a[i][2]));
	        int midn=a[i][0]+a[i][1]+a[i][2]-maxn-minn;
    cout<<maxn<<midn<<minn;
	return 0;
}
