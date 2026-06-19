#include<bits/stdc++.h>
using namespace std;
int a[100];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int count=1;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	int q=a[1];
	int t=0;
	sort(a+1,a+m*n+1,cmp);
	for(int i=1;i<=n*m;i++){
		//cout<<a[i];
		if(a[i]==q){
			t=i;
		}
	}
	int r=0;
	int c=t/n+1;
	if(c%2==1){
		r=t%n;
		if(r==0){
			r+=n;
			c--;
		}
	}
	else if(c%2==0){
		r=n+1-t%n;
		if(t%n==0){
			r=n;
			c--;
		}
	}
	
	cout<<c<<" "<<r;
	return 0;
}
