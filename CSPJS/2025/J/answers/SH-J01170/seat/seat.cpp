#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}int a1=a[1],so;
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--){
		if(a[i]==a1)so=n*m-i+1;
	}int shu=so/n;
	if(so%n==0){
		if(shu%2==0)cout<<shu<<" "<<1;
		else cout<<shu<<" "<<n;
	}else{
		shu+=1;
		if(shu%2==0)cout<<shu<<" "<<n-so%n+1;
		else cout<<shu<<" "<<so%n;
	}fclose(stdin);
	fclose(stdout);
	return 0;
}
