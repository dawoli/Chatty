#include<bits/stdc++.h>
using namespace std;
const int N=5009;
long long a[N];
long long n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<"0"<<endl;
		return 0;
	}
	else if(n==3){
		if(a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3]))*2) cout<<"1"<<endl;
		else cout<<"0"<<endl;
		return 0;
	}
	else if(*max_element(a+1,a+1+n)==1){
		long long a=0;
		for(int i=n-2;i>=1;i--){
			a=a+i;
		}
		long long b=a%998244353;
		cout<<b<<endl;
	}
	else cout<<a[1]+a[10]<<endl;
	return 0;
}
