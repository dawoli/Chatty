#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","w",stdin);
	freopen("seat.out","r",stdout);
	int n,m;
	cin>>n>>m;
	int a[m*n];
	for(int i = 0;i<m*n;i++){
		cin>>a[i];
	}
	int c;
	int d=a[0];
	sort(a,a+(m*n));
//	for(int i =0;i<m*n;i++){
//		cout<<a[i]<<" ";
//	} 
	for(int i = 0;i<m*n;i++){
		if(a[i]==d){
			c=i+1;
			break;
		}
	}
	c=m*n-c+1;
//	cout<<c;
	int g=c;
	for(int i = 0;i<n;i++){
		if(g%n!=0){
			g++;
		}
		else{
			break;
		}
	}
	int r1=g/n;
	int r2;
	if(r1%2==1){
		r2=c%m;
	}
	else{
		r2=n+1-c%m;
	}
	if(r2==0){
		r2=m;
	}
	cout<<r1<<" "<<r2;
	return 0;
} 

