#include <bits/stdc++.h>

using namespace std;
const int N=5010;
int n,a[N],al,b[N];
int mod= 998244353;
bool check(int x,int k){
	return b[k+x]-b[x-1]>2*a[k+x];
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	if(n==3){
		if(a[1]+a[2]>a[3]){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	for(int i=3;i<=n;i++){
		for(int j=1;i+j-1<=n;j++){
			if(check(j,i-1)){
				al=(al+1)%mod;
			}
		}
	}
	cout<<al;
	return 0;
} 
