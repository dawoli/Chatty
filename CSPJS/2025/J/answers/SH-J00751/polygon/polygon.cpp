#include<bits/stdc++.h>
using namespace std;
const int MAX=998244353;
int n;
int a[5];
int main(){
	freopen("polygon","r",stdin);
	freopen("polygon","w",stdout);
	cin>>n;
	if(n==3){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		if(a[1]+a[2]>a[3]){
			cout<<1;
		}
		else cout<<0;
	}else{
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		long long sum=0;
		for(int i=3;i<=n;i++){
			long long sum1=1,sum2=1;
			for(int j=n;j>=n-i+1;j--){
				sum1*=j;
			}
			for(int j=1;j<=i;j++){
				sum2*=j;
			}
			long long ans=sum1/sum2;
			sum+=ans;
		}
		cout<<sum%MAX;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
