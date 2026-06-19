#include <bits/stdc++.h>
using namespace std;
struct Po
{
	string s;
};
Po a[100];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	int ans=52;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		bool flag=0;
		cin>>a[i].s;
		for(int j=1;j<i;j++)
		{
			if(a[i].s==a[j].s)
			{
				flag=1;
				break;
			}
		}
		if(flag==0) ans--;
	}
	cout<<ans;
	return 0;
}
