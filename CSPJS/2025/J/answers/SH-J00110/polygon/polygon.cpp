#include<iostream>
using namespace std;
int a[5010];
int n;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int sum=0,maxn=-1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
		maxn=max(maxn,a[i]);
	}
	if(sum>2*maxn)
	{
		cout<<1<<endl;
	}
	else
	{
		cout<<0<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
