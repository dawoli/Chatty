#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
const int M=1e3+10;
typedef long long ll;
bool cmp(ll a,ll b)
{
	return a>b;
}
ll n,m,a[M],r,t,chu,yu;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	t=n*m;
	for(int i=1;i<=t;i++)
	{
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+t+1,cmp);
	for(int i=1;i<=t;i++)
	{
		if(a[i]==r)
		{
			chu=i/n,yu=i%n;
			if(yu==0)
			{
				if(chu%2==0) cout<<chu<<" "<<1;
				else cout<<chu<<" "<<n;
			}
			if(yu!=0)
			{
				if(chu%2!=0) cout<<chu+1<<" "<<n-yu+1;
				else cout<<chu+1<<" "<<yu;
			}
			return 0;
		}
	}
	return 0;
}

