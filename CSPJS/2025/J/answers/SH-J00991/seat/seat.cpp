#include<bits/stdc++.h>
using namespace std;
int a[300];
bool cmp(int a1,int a2){
	return a1>a2;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int R;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			R=a[1];
		}
	}
	sort(a+1,a+n*m+1,cmp);
	int x;
	for(int i=1;i<=n*m;i++){
		if(a[i]==R){
			x=i;
			break;
		}
	}
	int c;
	if(x%n==0){
		c=x/n;
	}else{
		c=x/n+1;
	}
	int r;
	int y=x-n*(c-1);
	if(c%2==1){
		r=y;
	}else{
		r=n-y+1;
	}
	cout<<c<<" "<<r;
}
