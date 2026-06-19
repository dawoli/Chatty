#include <bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",&a[i]); 
	int aa=a[1],id;
	sort(a+1,a+1+n*m,greater<int>());
	for(int i=1;i<=n*m;i++)
		if(a[i]==aa)
			id=i;
	int col=ceil(id*1.0/n),row;
	id-=(col-1)*n;
	if(col%2) row=id;
	else row=n-id+1;
	printf("%d %d",col,row);
	return 0;
}
