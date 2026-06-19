#include<bits/stdc++.h>
using namespace std;
int n,m,R,a[105],adr;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	R=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--){
		if(a[i]==R){
			adr=n*m-i+1;
			break;
		}
	}
	int jud=(adr+n-1)/n,ans;
	cout<<jud<<' ';
	ans=adr%n;
	if(jud%2){
		if(ans==0){
			cout<<n;
		}else{
			cout<<ans;
		}
	}else{
		cout<<n-adr%n+1;
	}
	//#Shang4Shan3Ruo6Shui4
	return 0;
}
