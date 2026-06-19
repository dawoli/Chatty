#include <iostream>
#include <algorithm>
using namespace std;
int n,m,a[101],c,r;
bool cmp(int x,int y) { return x>y; }
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1; i<=n*m; i++) cin>>a[i];
	int R=a[1],id;
	sort(a+1,a+n*m+1,cmp);
	for (int i=1; i<=n*m; i++)
		if (a[i] == R)
			id = i;
	int num=id%n;
	if (num == 0) c=id/n;
	else c=id/n+1;	
	cout<<c<<' ';
	if (c%2 == 1)
	{
		if (num == 0) r=n;
		else r=id%n;
	}
	else
	{
		if (num == 0) r=1;
		else r=n-num+1;
	}
	cout<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
