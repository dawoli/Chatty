#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[10005];

bool cmp(int x,int y)
{
	return x>y;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int R_chj;
	for(int i = 1;i<=n*m;i++)
	{
		cin>>a[i];
		if(i==1)
		{
			R_chj=a[i];
		}
	}
	sort(a+1,a+n*m+1,cmp);
	int R_seat=0;
	for(int i = 1;i<=n*m;i++)
	{
		if(a[i]==R_chj)
		{
			R_seat=i;
			break;
		}
	}
//	cout << R_seat<<endl;
	int lie=(R_seat+n-1)/n;
	cout << lie<<' ';
	if(lie%2==1)
	{
		if(R_seat%n)
		cout << R_seat%n;
		else
		cout << n;
	}
	else
	{
		cout << n-R_seat%n+1;
	}
	return 0;
}

