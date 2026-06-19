#include<iostream>
using namespace std;
long long c[150]={ },n[150]={ };
void solve()
{
	for(int i=3;i<=92;i++)
	{
		c[i]=c[i-1]+c[i-2];
		n[i]=n[i-1]+n[i-2];
	}
}
long long search(long long m)
{
	for(int i=0;i<=92;i++)
	{
		if(c[i]==m) return n[i];
		if(c[i]>m) return n[i-1]+search(m-c[i-1]);
	}
}
int main()
{
	freopen("infinit.in","r",stdin);
	freopen("infinit.out","w",stdout);
	int q;
	long long a,b,x,y;
	cin>>q;
	c[0]=0;c[1]=1;c[2]=2;
	n[1]=n[2]=1;
	solve();
	for(int i=1;i<=q;i++)
	{
		cin>>a>>b;
		x=search(a-1);
		y=search(b);
		cout<<y-x<<endl;
	}
	return 0;
}
