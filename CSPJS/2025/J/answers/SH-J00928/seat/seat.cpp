#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int k=0;
	int mx=0;
	for(int i=1;i<=n*m;i++){
		int x;cin>>x;
		if(i==1)k=x;
		if(x>k)mx++;
	}
	mx++;
	int ppp=0,qqq=0;
	if(mx%n==0)qqq=mx/n;
	else qqq=mx/n+1;
	if(qqq%2==0)ppp=m-(mx%m)+1;
	else if(m==1) ppp=mx%m+1;
	else ppp=mx%m;
	cout<<qqq<<' '<<ppp<<'\n';
	return 0;
}
