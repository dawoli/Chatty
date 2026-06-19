#include<bits/stdc++.h>
#define M 998244353
using namespace std;

int n,mx,ans,a[5010],dsy[2][25000010];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	sort(a+1,a+n+1);
	dsy[0][0]=1;
	for(int i=1;i<n;i++){
		for(int j=0;j<=mx*i;j++) dsy[i%2][j]=0;
		for(int j=0;j<=mx*i;j++){
			dsy[i%2][j+a[i]]=(dsy[i%2][j+a[i]]+dsy[(i-1)%2][j])%M;
			dsy[i%2][j]=(dsy[i%2][j]+dsy[(i-1)%2][j])%M;
		}
		for(int j=a[i+1]+1;j<=mx*i;j++) ans=(ans+dsy[i%2][j])%M;
	}
	cout<<ans;
	return 0;
}
