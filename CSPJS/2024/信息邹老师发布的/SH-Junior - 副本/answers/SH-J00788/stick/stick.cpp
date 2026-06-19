#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e6+10;
void f()
{
	ll n;
	cin>>n;
	int s=n/7,r=n%7;
	if(n==1)
	{
		cout<<-1<<endl;
		return;
	}
	if(r==1)
	{
		s--;
		cout<<10;
	}
	if(r==2) cout<<1;
	if(r==3)
	{
		if(s>0)
		{
			s--;
			cout<<22;
		}
		else cout<<7;
	}
	if(r==4)
	{
		if(s>0)
		{
			s--;
			cout<<20;
		}
		else cout<<4;
	}
	if(r==5) cout<<2;
	if(r==6) cout<<6;
	for(int i=1;i<=s;i++) cout<<8;
	cout<<endl;
}
int main()
{
	freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	while(t--) f();
	return 0;
}

