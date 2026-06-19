#include<bits/stdc++.h>
using namespace std;
int a,b,n,m,x[200];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int cnt=1;
	for(int i=1;i<=n*m;i++){
		cin>>x[i];
		if(x[i]>x[1])cnt++;
	}
	a=(cnt-1)/n+1;
	b=cnt+n-(a*n);
	if(a%2==1){
		cout<<a<<" "<<b;
	}else{
		cout<<a<<" "<<n+1-b;
	}
	
	return 0;
}
