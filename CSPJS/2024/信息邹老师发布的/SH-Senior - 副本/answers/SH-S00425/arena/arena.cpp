#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m;
long long a0[N],a[N],c[N],ans[N],x[5];
bitset<500> d[20];
bool twok(int i)
{
	if(i==1)
		return false;
	while(i>=2)
	{
		if(i%2==1)
			return false;
		i/=2;
	}
	return true;
}
int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	long long T,i,K;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a0[i];
	for(i=1;i<=n;i++)
		cin>>c[i];
	for(i=1;i<=20;i++)
		if(pow(2,i)>=n){
			K=i;
			break;
		}
	for(i=1;i<=K;i++)
		cin>>d[i];
	cin>>T;
	while(T--)
	{
		long long sum=0;
		for(i=0;i<=3;i++)
			cin>>x[i];
		for(i=1;i<=n;i++)
			a[i]=(a0[i]^x[i%4]);
		c[1]=1;
		for(i=1;i<=m;i++)
			sum^=(i*ans[c[i]]);
		cout<<sum<<endl;
	}
	return 0;
}

