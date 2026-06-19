#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
	int v,id;
	bool operator < (const struct node &t) const
	{
		return v>t.v;
	}
} NODE,*PNODE;
NODE arr[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,i,id,x,y;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n*m;++i)
	{
		scanf("%d",&arr[i].v);
		arr[i].id=i;
	}
	sort(arr+1,arr+n*m+1);
	for(i=1;i<=n*m;++i)
	{
		if(arr[i].id==1)
		{
			id=i;
			break;
		}
	}
	y=(id-1)/n+1;
	x=(id-1)%(2*n)+1;
	x=x<=n?x:(2*n-x+1);
	printf("%d %d",y,x);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
