#include <bits/stdc++.h>
using namespace std;

int a[101],n,m,r,k;
bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin >> n >> m;
	int t=n*m;
	for(int i=1;i<=t;i++)
	{
		cin >> a[i];
	}
	r=a[1];
	sort(a+1,a+t+1,cmp);

	for(int i=1;i<=t;i++)
	{
		if(a[i]==r)
		{
			k=i;
		}
	}
	int p=(k-1)/n+1,q=(k-1)%n+1;
	cout << p << " ";
	if(p%2==1)
	{
		cout << q;
	}
	if(p%2==0)
	{
		cout << n-q+1;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
