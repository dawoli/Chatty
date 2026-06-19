#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
int a[N];
long long n;
int maxn=-0x3f3f3f3f;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	if(n<=3){
		if(n==1){
			cout<<0;
			return 0;
		}
		else if(n==2){
			cout<<0;
			return 0;
		}
		else if(n==3){
			maxn=max(max(a[1],a[2]),a[3]);
			int sum=a[1]+a[2]+a[3];
			if(sum>2*maxn){
				cout<<1;
				return 0;
			}
			else{
				cout<<0;
				return 0;
			}
		}
	}
	else{
		long long k=n*(n-1)*(n-2);
		long long m=k%998244353;
		cout<<m;
		return 0;
	}
	return 0;
}
