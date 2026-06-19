#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
	int ai,id;
	bool operator < (const struct node & t) const
	{
		return ai>t.ai; 
	}
}NODE;
int n,m;
NODE a[2005];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int pos=-1;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;++i)
	{
		scanf("%d",&a[i].ai);
		a[i].id=i;
	}
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;++i)
	{
		if(a[i].id==1)
		{
			pos=i;
			break;
		}
	}
	int x=1,y=1,d=0;	
	for(int i=2;i<=pos;++i)
	{
		if(d==0)
		{
			x++;
			if(x>n)
			{
				d=1;
				x=n;
				y++;
			}
		}
		else
		{
			x--;
			if(x<1)
			{
				d=0;
				x=1;
				y++;
			}
		}
	}
	printf("%d %d\n",y,x);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
