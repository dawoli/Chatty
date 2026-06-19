#include <bits/stdc++.h>
using namespace std;
struct ss
{
	int a;
	int p;
}s[105];
bool com1(ss x,ss y)
{
	return x.a>y.a;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>s[i].a;
		s[i].p=i;
	}
	sort(s+1,s+1+n*m,com1);
	int tem,line;
	for(int i=1;i<=n*m;i++)
	{
		if(s[i].p==1) 
		{
			tem=i;
			break;
		}
	}
	if(tem%n==0) line=tem/n;
	else line=tem/n+1;
	if(line%2==1)
	{
		if(tem%n==0) cout<<line<<" "<<n;
		else cout<<line<<" "<<tem%n;
	}
	else
	{
		if(tem%n==0) cout<<line<<" "<<1;
		else cout<<line<<" "<<n-tem%n+1;
	}
	return 0;
}
