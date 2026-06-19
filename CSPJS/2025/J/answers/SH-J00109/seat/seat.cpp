#include<bits/stdc++.h>
using namespace std;

int m,n,a[105];

int main(){
	//²»ÄÜÉ¾£¡£¡£¡£¡£¡£¡ 
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1];
	sort(a+1,a+n*m+1);
	int k=lower_bound(a+1,a+m*n+1,x)-a;
	k=n*m-k+1;
	int c=(k-1)/n+1;
	if(c&1){
		cout<<c<<' '<<(k-1)%n+1;
	}
	else{
		cout<<c<<' '<<n-(k-1)%n;
	}
	return 0;
}

