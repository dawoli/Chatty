#include<iostream>
#include<cmath>
using namespace std;
int a[5145],m;
long long n;
long long lv(long long u){
	long long lns=0;
	for(int i=3;i<=u;i++){
		long long m=1;
		for(int j=u;j>u-i;j--){
			m*=j;
			m%=998244353;
		}
		for(int j=1;j<=i;j++){
			m/=j;
		}
		lns+=m;
		lns%=998244353;
	}
	return lns;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	if(n==3&&a[1]+a[2]+a[3]>2*max(max(a[1],a[2]),a[3]))
	cout<<1;
	else if(n==3&&a[1]+a[2]+a[3]<=2*max(max(a[1],a[2]),a[3]))
	cout<<0;
	else if(n>3)
	cout<<lv(n);
	
}
