#include<bits/stdc++.h>
using namespace std;
int arr[1005];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int i,n,m,a,x,id;
	scanf("%d %d",&n,&m);
	scanf("%d",&a);
	arr[1]=a;
	for(i=2;i<=n*m;++i)
		scanf("%d",&arr[i]);
	sort(arr+1,arr+1+n*m);
	for(i=n*m;i>=1;--i)
		if(arr[i]==a)
		{
			id=n*m-i+1;
			break;
		}
	if(id%n==0)
		x=id/n;
	else
		x=id/n+1;
	id-=(x-1)*n;
	if(x%2==0)
		printf("%d %d",x,m-id+1);
	else
		printf("%d %d",x,id);
	return 0;
}
