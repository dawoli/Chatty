#include<iostream>
using namespace std;
int b[10005]={0};
int n,cnt=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	long long cnt=0;
	int as=1,bs=1;
	for(int i=3;i<=n;i++){
		as=1;bs=1;
		for(int j=n;j>=n-i+1;j--) as*=j%998244353;
		for(int j=i;j>=1;j--) bs*=j%998244353;
		cnt+=as/bs%998244353;
	}
	cout<<cnt;
	return 0;
}
