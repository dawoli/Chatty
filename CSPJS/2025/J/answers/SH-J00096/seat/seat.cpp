#include<bits/stdc++.h>
using namespace std;
struct student
{
	int score;
	int x,y;	
}a[105];
int n,m;
bool cmp(student &a,student &b)
{
	return a.score>b.score;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].score;
	}
	int pos=a[1].score;
	sort(a+1,a+n*m+1,cmp);
	if(a[1].score==pos)
	{
		cout<<1<<" "<<1;
		return 0;
	}
	int add=1;
	a[1].x=a[1].y=1;
	for(int i=2;i<=m*n;i++)
	{
		a[i].x=a[i-1].x+add;
		a[i].y=a[i-1].y;
		if(a[i].x>n)
		{
			add=-1;
			a[i].x=n;
			a[i].y=a[i-1].y+1;
		}
		else if(a[i].x<1)
		{
			add=1;
			a[i].x=1;
			a[i].y=a[i-1].y+1;
		}
		if(a[i].score==pos)
		{
			cout<<a[i].y<<" "<<a[i].x;
			break;
		}
	}
	return 0;
}
