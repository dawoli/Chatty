#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,m,sum[505];
int a[505],c[505],ls[505],sls[505];
int num0,num1;
//ls is the number of the possible position of every employees(the first x 0s)
int A(int big, int small){
	int k=1;
	for(int i=big-small+1;i<=big;i++) k=k*i%mod;
	return k;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char x;
		cin>>x;
		a[i]=abs(x-'1');
		if(a[i]==0) num0++;
		else num1++;
		sum[i]=sum[i-1]+a[i];//here I change a[i] that 0 is in and 1 is out
		//so sum here is just reject
//		cout<<a[i]<<" "<<sum[i]<<endl;
	}
	if(sum[n]>n-m){
		cout<<0<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++){
		int t=c[i];
		for(int j=1;j<=n;j++){
			if(sum[j-1]>t){//BEFORE HIM, so j-1
				ls[i]=j-sum[j];
				break;
			}
		}
	}
	if(sum[n]==0){
		int ans=1;
		for(int i=1;i<=n;i++){
			ans=ans*i%mod;
		}
		cout<<ans<<endl;
		return 0;
	}
}
