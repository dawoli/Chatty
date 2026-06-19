#include<iostream>
using namespace std;
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int a1;
	cin>>a1;
	int place=1;
	for(int i=1;i<n*m;i++){
		int a;
		cin>>a;
		if(a>a1) place++;
	}
	int c;
	if(place%n==0){
		c=place/n;
	}else{
		c=place/n+1;
	}
	int r;
	if(place%n==0){
		r=n;
	}else{
		r=place%n;
	}
	if(c%2==0){
		r=n-r+1;
	}
	cout<<c<<" "<<r;
	return 0; 
} 
