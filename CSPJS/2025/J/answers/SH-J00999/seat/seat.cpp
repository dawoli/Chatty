#include <bits/stdc++.h>
using namespace std;
int s[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&s[i]);
	}
	int x=s[1];
	sort(s+1,s+n*m+1);
	int xx;
	for(int i=n*m,j=1;i>=1;i--,j++)
	{
		if(s[i]==x)
		{
			xx=j;
			break;
		}
	}
	//cout<<xx<<endl;
	int c=1,r=2,f=1,ff=1;;
	if(xx==1)
	{
		cout<<c<<" "<<1;
		return 0;
	}
	for(int i=2;i<=n*m;i++)
	{
		if(i==xx)break;
		if(r!=1 && r!=n)
		{
			if(ff)
			{
				r++;
			}
			else
			{
				r--;
			}
		}
		else
		{
			if(f)
			{
				f--;
				c++;
				if(ff)
				{
					ff--;
				}
				else
				{
					ff++;
				}
			}
			else if(!f && ff)
			{
				f++;
				r++;
			}
			else if(!f && !ff)
			{
				f++;
				r--;
			}
		}
	}
	printf("%d %d",c,r);
	return 0;
}
