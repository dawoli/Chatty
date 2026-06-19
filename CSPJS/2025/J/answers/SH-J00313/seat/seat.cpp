#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int biao=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==biao)
		{
			biao=i;
			break;
		}
	}
	cout<<ceil(biao*1.0/n)<<" ";
	int mm=ceil(biao*1.0/n);
	if(mm%2==1)
	{
		if(biao%n==0)   cout<<n<<"\n";
		else    cout<<biao%n<<"\n";
	}
	else
	{
		if(biao%n==0)   cout<<1<<"\n";
		else    cout<<n-biao%n<<"\n";
	}
	return 0;
}
