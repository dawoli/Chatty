#include<bits/stdc++.h>
using namespace std;
#define p 998244353
int a[5010],b[5010]; 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	int n,k=1,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(a[1]+a[2]<=5000)b[a[1]+a[2]]=1; 
	for(int i=3;i<=n;i++){
		int s=0;
		for(int j=1;j<=a[i];j++)s=(s+b[j])%p;
		ans=((ans+k-s)%p+p)%p;
		for(int j=5000;j>=1;j--)if(j+a[i]<=5000)b[j+a[i]]=(b[j+a[i]]+b[j])%p;
		for(int j=1;j<i;j++)if(a[i]+a[j]<=5000)b[a[i]+a[j]]=(b[a[i]+a[j]]+1)%p;
		k=(2*k+i-1)%p;
	}
	cout<<ans;
	return 0;
}
