#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=100009;
const ll num[10]={6,2,5,5,4,5,6,3,7,6};
ll n,t,sum;
ll stick[N];
bool can[N];
void Inv()
{
	memset(stick,-1,sizeof(stick));
	ll i=1;
	while(stick[50]==-1)
	{
		t=i;
		sum=0;
		while(t)
		{
			sum+=num[t%10];
			t/=10;
		}
		if(stick[sum]==-1)stick[sum]=i;
		i++;
	}
}
signed main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll T;
	cin>>T;
	Inv();
	while(T--)
	{
		cin>>n;
//		for(ll i=1;i<=50;i++)cout<<stick[i]<<endl;
		if(n<=50)
		{
			cout<<stick[n]<<endl;
			continue;
		}
//		if(n%7==0)
//		{
//			for(ll i=1;i<=n/7;i++)
//			  cout<<8;
//			cout<<endl;
//			continue;
//		}
//		if(n%7==1)
//		{
//			cout<<10;
//			for(ll i=1;i<=(n-8)/7;i++)
//			  cout<<8;
//			cout<<endl;
//			continue;
//		}
		switch(n%7)
		{
			case 1:cout<<108;n-=15;break;
			case 2:cout<<188;n-=16;break;
			case 3:cout<<200;n-=17;break;
			case 4:cout<<208;n-=18;break;
			case 5:cout<<288;n-=19;break;
			case 6:cout<<688;n-=20;break;
			case 0:cout<<888;n-=21;break;
		}
		for(ll i=1;i<=n/7;i++)cout<<8;
		cout<<endl;
	}
	return 0;
}

