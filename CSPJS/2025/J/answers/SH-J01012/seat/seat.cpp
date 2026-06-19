#include<bits/stdc++.h>
using namespace std;
int a,b,e=0,c[1000],d=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a*b;i++){
		cin>>c[i];
	}
	for(int i=2;i<=a*b;i++){
		if(c[i]>c[1]){
			d++;
	}
	}
	if(d%a==0&&(d/a)%2==1){
		e=d/a;
	}
	else if(d%a==0&&(d/a)%2==0)
		e=d/a;
	else
		e=d/a+1;
	cout<<e<<' ';
	if(((d-1)/a)%2==0){
		if(d%a==0)
			cout<<a;
		else
			cout<<d%a;
}
	else
		if(d%a==0)
			cout<<1;
		else
			cout<<a+1-d%a;
}
