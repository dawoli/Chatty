#include<bits/stdc++.h>
using namespace std;
int a,b,n,m,ans;
int main(){
	freopen("seat3.in","r",stdin);
	//freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	ans=1;
	for(int i=2;i<=n*m;i++){
		cin>>b;
		if(a<b){
			ans++;
		}
	}
	if((ans/n)%2==0){
		if(ans%n==0){
			cout<<ans/n<<' '<<1;
			return 0;
		}
		cout<<ans/n+1<<' '<<ans%n;
		return 0;
	}
	if(ans%n==0){
		cout<<ans/n<<' '<<n;
		return 0;
	}
	cout<<ans/n+1<<' '<<n-(ans%n-1);
	return 0;
}
