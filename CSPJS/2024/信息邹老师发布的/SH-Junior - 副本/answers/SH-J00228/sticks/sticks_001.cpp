#include<bits/stdc++.h>
using namespace std;
struct node 
{
	int t;
	int h;
}a[10][10];
int b[10];
void print(int len,int fir,int num)
{
	if(a[fir][num].h==-1)
	{
		cout<<-1<<endl;
		return ;
	}
	if(a[fir][num].h!=-2)
	{
		cout<<a[fir][num].h;
	}
	for(int i=1;i<=a[fir][num].t;i++)
	{
		cout<<0;
	}
	for(int i=1;i<=(len-a[fir][num].t);i++)
	{
		cout<<8;
	}
	cout<<endl;
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	a[0][0].t=1;
	a[0][0].h=-2;
	a[0][0].t=0;
	a[0][0].h=-1;
	a[1][1].t=1;
	a[1][1].h=1;
	a[1][2].t=0;
	a[1][2].h=-1;
	a[2][1].t=0;
	a[2][1].h=1;
	a[3][1].t=2;
	a[3][1].h=2;
	a[3][2].t=1;
	a[3][2].h=4;
	a[3][3].t=0;
	a[3][3].h=7;
	a[4][1].t=1;
	a[4][1].h=2;
	a[4][2].t=0;
	a[4][2].h=4;
	a[5][1].t=0;
	a[5][1].h=2;
	a[6][1].t=0;
	a[6][1].h=6;
	b[0]=2;
	b[1]=2;
	b[2]=1;
	b[3]=3;
	b[4]=2;
	b[5]=1;
	b[6]=1;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		int y=x/7;
		x%=7;
		for(int i=1;i<=b[x];i++)
		{
			if(a[x][i].t<=y)
			{
				print(y,x,i);
				break;
			}
		}
	}
	
}

























