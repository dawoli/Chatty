#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a1a[111];
int a,s,d;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>a>>s;
	for(int i=0;i<a*s;i++)
		cin>>a1a[i];
	d=a1a[0];
	sort(a1a,a1a+a*s);
	for(int i=0;i<a*s;i++)
		if(a1a[i]==d)
		{
			d=i;
			break;
		}
		d=a*s-d;
	cout<<(d-1)/a+1<<' ';
	if(((d-1)/a)%2)
		if(d%a)cout<<a-d%a+1;
		else cout<<1;
	else cout<<((d-1)%a)+1;
	return 0;
}
