#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,f;
	int g=0;
	cin>>n>>m;
	int a[n*m]={};
	cin>>f;
	a[0]=f;
	for(int i=1;i<n*m;i++){
		cin>>a[i];
		}
	sort(a,a+n*m);
	for(int i=n*m-1;i>=0;i--){
		if(a[i]>=f){
			g+=1;
		}
	}
	if((g/n)%2==1){
		if(g%n==0){
			cout<<g/n<<" "<<n;
		}else{
			cout<<g/n+1<<" "<<n-g%n+1;
		}
	}else{
		if(g%n==0){
			cout<<g/n<<" "<<1;
		}else{
			cout<<g/n+1<<" "<<g%n;
		}
	}
	return 0;
}
