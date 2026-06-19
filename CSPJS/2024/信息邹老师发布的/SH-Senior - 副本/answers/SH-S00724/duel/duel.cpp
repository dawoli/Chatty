#include<iostream>
#include<algorithm>
using namespace std;
int n,a[100001];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==1)
	{
		cout<<1;
		return 0;
	}
	sort(a+1,a+n+1);
	int s=0,ts=0,ans=0;
	for(int i=2;i<=n;i++)
	{
		if(a[i]>a[i-1])
		{
			ans++;
			s+=ts;
			ts=0;
		}
		else
		{
			ts++;
			if(s!=0)
			{
				s--;
				ans++;
			}
		}
	}
	cout<<n-ans;
}
