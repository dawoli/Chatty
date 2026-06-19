#include<bits/stdc++.h>
using namespace std;
#define N 5005
#define R 998244353
int n,a[N],mx;
long long ans;
void dfs(int i,int sum,int m,int t){
	if(i==n+1){
		if(sum>2*m&&t>=3){ans=(ans+1)%R;}
		return;
	}
	dfs(i+1,sum+a[i],max(m,a[i]),t+1);
	dfs(i+1,sum,m,t);
}
long long fast_pow(long long a,int b){
	long long res=1;
	while(b){
		if(b%2==0){
			a=(a*a)%R;
			b/=2;
		}
		else{
			res=(res*a)%R;
			b-=1;
		}
	}
	return res;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(mx==1){
		ans=(fast_pow(2,n)-1-n-n*(n-1)/2+R)%R;}
	else{
		dfs(1,0,0,0);}
	cout<<ans;
	return 0;
}
