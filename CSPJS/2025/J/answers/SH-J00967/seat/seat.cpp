#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10009];
int x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int k=1;
	for(int i=2;i<=n*m;i++){
		if(a[i]>a[1]){
			k++;
		}
	} 
	int p=(k-1)/n;
	int q=k%n;
	if(q==0){
		q=n;
	}
	y=p+1;
	if(p%2==1){
		x=n+1-q;
	}
	else{
		x=q;
	}
	cout<<y<<" "<<x;
	return 0;
}
