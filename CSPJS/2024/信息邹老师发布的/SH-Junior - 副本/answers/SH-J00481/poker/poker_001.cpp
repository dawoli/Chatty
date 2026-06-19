#include<iostream>
#include<algorithm>
using namespace std;
pair<char,char>p[53];
int n,ans;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	if(n==1)
	{
		cout<<51<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>p[i].first>>p[i].second;
	}
	ans=n;
	sort(p+1,p+n+1);
	for(int i=2;i<=n;i++)
	{
		if(p[i].first==p[i-1].first&&p[i].second==p[i-1].second)
		{
			ans--;
		}
	}
	cout<<52-ans;
	return 0;
}
