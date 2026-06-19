#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m+5];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	a[0]=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m/2;i++){
		swap(a[i], a[n*m-i+1]);
	}
	float b;
	for(int i=1;i<=n*m;i++){
		if(a[i]==a[0]){
			b=i;
			break;
		}
	}
	float c=b*1.0/m;
	int e;
	if(c>int(c)){
		cout<<int(c+1);
		e=int(c+1);
	}
	else{
		cout<<int(c);
		e=int(c);
	}
	cout<<" ";
	int d=int(b)%m;
	if(d==0){
		d=m;
	}
	if(e%2==0){
		cout<<m-d+1;
	}
	else cout<<d;
	return 0;
}
