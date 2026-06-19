#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
int n,ans;
map<int,int>m;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	if(n==1)
	{
		cout<<1;
		return 0;
	}
	ans=n;
	for(int i=1;i<=n;i++)
	{
		int tmp;
		cin>>tmp;
		m[tmp]++;
	}
	int undied=0;
	bool flag=false;
	for(auto i:m)
	{
		
		if(flag)
		{
			if(undied>=i.second)
			{
				ans-=i.second;
				undied-=i.second;
			}
			else
			{
				ans-=undied;
				undied=0;
			}
		}
		undied+=i.second;
		flag=true;
		//cout<<i.first<<" "<<i.second<<" "<<ans<<" "<<undied<<endl;
	}
	cout<<ans;
}
