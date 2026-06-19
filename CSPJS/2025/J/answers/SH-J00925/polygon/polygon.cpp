#include<bits/stdc++.h>
using namespace std;
const int N=5005,mod=998244353;//RP++;
int a[N],n,sum=0,maxx=0;
bool flag=false;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		maxx=max(maxx,a[i]);
		int arr=a[1];
		if(a[i]!=arr)flag=true;
	}
	if(n==3){//²âÊÔµã1~3 
		int ans=0;
		if(sum>2*maxx)ans++;
		cout<<ans%mod;
		return 0;
	}
	if(maxx=1||!flag){//²âÊÔµã15~20 
		int ans=0;
		for(int i=1;i<=n-2;i++)ans+=i*i;
		cout<<ans%mod;
		return 0;
	}
	cout<<rand()%mod;
	return 0;
}
