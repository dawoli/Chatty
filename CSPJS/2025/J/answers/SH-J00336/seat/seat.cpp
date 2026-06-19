#include <bits/stdc++.h>
using namespace std;
int st[11][11];
int cj[107];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin >> n >> m;
	for(int i=1;i<=m*n;i++)
	{
		cin >> cj[i];
	}
	int cjj=cj[1];
	sort(cj+1,cj+1+n*m);
	int dw;
	for(int i=1;i<=m*n;i++)
	{
		if(cj[i]==cjj)
		{
			dw=m*n-i+1;
			break;
		}
	}
	if(dw%n==0)
	{
		if((dw/n)%2==1)cout << dw/n <<" "<< n;
		else cout << dw/n <<" "<< 1;
	} 
	else
	{
		if((dw/n+1)%2==1)cout << dw/n +1 <<" "<< dw%n;
		else cout << dw/n+1 <<" "<< n-dw%n+1;
	}
	return 0; 
}
