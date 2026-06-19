#include<bits/stdc++.h>
using namespace std;
int a[113];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,m,aa=0,b,num,aaa;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	num=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++){
		if(num==a[i]){
			aaa=n*m-i+1;
		}
	}
	if(aaa%n!=0){
		aa=aaa/n+1;
	}
	else{
		aa=aaa/n;
	}
	if(aa%2==1){
		b=(aaa-1)%m+1;
	}
	else{
		b=m-(aaa%m-1);
	}
	cout<<aa<<" "<<b;
	return 0;
}
//3 3
//94 95 96 97 98 99 100 93 92
//3 1
