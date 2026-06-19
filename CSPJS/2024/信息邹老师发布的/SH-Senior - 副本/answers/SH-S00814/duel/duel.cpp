#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int r[100005];
bool d[100005];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	bool f=0;
	for(int i = 1;i <= n;i++)
	{
		 cin>>r[i];
		 if(r[i]>2)f=1;
	}
	if(!f)
	{
		int cnt1=0,cnt2=0;
		for(int i = 1;i <= n;i++)
		{
			if(r[i]==1)cnt1++;
		}
		cnt2=n-cnt1;
		cout<<min(cnt1,cnt2);
		return 0;
	}
	sort(r+1,r+n+1);
	int life=n;
	for(int i = 2;i <= n;i++)
	{
		if(r[1]==r[i])continue;
		for(int j = i-1;j>=1;j--)
		{
			if(!d[j]&&r[j]<r[i])
			{
				life--;
				d[j]=1;
				break;
			}
		}
	}
	cout<<life;
	return 0;
}
