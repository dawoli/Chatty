#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[110],n,m,num=1,c,r;
	cin>>n>>m>>a[1];
	for(int i=2;i<n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]) num++;
	}if(num%n) c=num/n+1;
	else c=num/n;
	if(num%n==0){
		if(c%2) r=n;
		else r=1;
	}
	else{
		if(c%2) r=num%n;
		else r=n-num%n+1;
	}cout<<c<<" "<<r;
	return 0;
}//45m
