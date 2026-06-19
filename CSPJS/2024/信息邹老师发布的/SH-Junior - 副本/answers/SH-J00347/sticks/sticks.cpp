#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int n;
	long long a[55];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]%7==0) for(int j=1;j<=a[i]/7;j++) cout<<8;
		else if(a[i]%6==0) for(int j=1;j<=a[i]/6;j++) cout<<6;
		else if(a[i]%5==0) for(int j=1;j<=a[i]/5;j++) cout<<5;
		else if(a[i]%4==0) for(int j=1;j<=a[i]/4;j++) cout<<4;
		else if(a[i]%3==0) for(int j=1;j<=a[i]/3;j++) cout<<3;
		else if(a[i]%2==0) for(int j=1;j<=a[i]/2;j++) cout<<2;
		else cout<<-1;
		cout<<'\n';
	}
	return 0;
}
