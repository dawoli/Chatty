#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int k[101];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int numm=n*m;
	int rr;
	for(int i=1;i<=numm;i++)
	{
		cin>>k[i];
		if(i==1) rr=k[i];
	}
	sort(k+1,k+numm+1,cmp);
	int kk;
	for(int i=1;i<=numm;i++)
	{
		if(k[i]==rr)
		{
			kk=i;
			break;
		}
	}
	int a=kk%n;
	int b=kk/n;
	if(a==0)
	{
		if(b%2==1) cout<<b<<" "<<n<<endl;
		else cout<<b<<" "<<1<<endl;
	}
	else
	{
		if((b+1)%2==1) cout<<b+1<<" "<<a<<endl;
		else cout<<b+1<<" "<<n<<endl; 
	}
	return 0;
}
