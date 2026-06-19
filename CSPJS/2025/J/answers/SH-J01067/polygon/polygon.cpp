#include<bits/stdc++.h>
using namespace std;
int a[10005],n=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<+n;i++)
		scanf("%d",&a[i]);
	printf("%d",2*n-1);
	return 0;
}
