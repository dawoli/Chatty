#include<bits/stdc++.h>
using namespace std;
int a[105];
int R1,R2;
int m,n,R,Rs;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+(m*n)+1);
	for(int i=1;i<=m*n;i++){
		if(R==a[i]){
			Rs=n*m-i+1;
			break;
		}
	}
	R1=Rs/n;
	R2=Rs%n;
	if(R2!=0){
		R1++;
	}
	if(R1%2==1&&R2!=0){
		cout<<R1<<" "<<R2;
	}else if(R1%2==1&&R2==0){
		cout<<R1<<" "<<n;
	}else if(R1%2==0&&R2!=0){
		cout<<R1<<" "<<n+1-R2;
	}else if(R1%2==0&&R2==0){
		cout<<R1<<" "<<1;
	}
	return 0;
}
