#include<bits/stdc++.h> 
using namespace std;
int n,m,sit;
int a[109];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=(n*m);i++){
		cin>>a[i];
	}
	int cnt=n*m;
	int get=a[1];
	sort(a+1,a+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		if(a[i]==get){
			sit=i;
			break;
		}
	}
	int c,r;
	c=((sit-1)/n+1);
	if(c%2==1){
		r=sit%n;
		if(r==0){
			r=n;
		}
	}
	else{
		int k=sit%n;
		if(k==0){
			k=n;
		}
		r=n-k+1;
	}
	cout<<c<<" "<<r;
	return 0;
}
