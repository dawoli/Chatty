#include<bits/stdc++.h>
using namespace std;
int n,m,x,ni,nj,cg=1;
int mp[15][15];
struct node
{
	int val,id;
}a[110];
bool cmp(node a,node b)
{
	return a.val>b.val;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	x=n*m;
	for(int i=1;i<=x;i++)
	{
		cin>>a[i].val;
		a[i].id=i;
	}
	sort(a+1,a+x+1,cmp);
	ni=1,nj=0,cg=1;
	for(int i=1;i<=x;i++)
	{
		if(nj+cg<1||nj+cg>n)
		{
			ni++;
			nj++;
			if(cg==1)
			{
				cg=-1;
			}
			else
			{
				cg=-1;
			}
		}
		nj+=cg;
		mp[ni][nj]=a[i].val;
		if(a[i].id==1)
		{
			cout<<ni<<" "<<nj<<endl;
			break;
		}
	}
}
