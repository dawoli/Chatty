#include<iostream>
using namespace std;
int a[101000],n,tmp,ans;
bool ok;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++) 
	{
		ok=true;
		for(int j=1;j<=n-1;j++)
		{
			if(a[j]>a[j+1])
			{
				ok=false;
				tmp=a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
			}
		}
		if(ok==true)
		{
			break;
		}
	}
	int att=1,def=1;
	for(;def<=n;def++)
	{
		for(;att<=n;att++)
		{
			if(a[att]>a[def])
			{
				ans++;
				att++;
				break;
			}
		}
	}
	cout<<n-ans;
	return 0;
}
