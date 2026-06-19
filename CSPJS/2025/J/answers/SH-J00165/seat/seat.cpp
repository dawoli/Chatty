#include<bits/stdc++.h>
using namespace std;
int n,m,a[1010],x,y,R;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		
	}
	R=a[0];
	
	for(int i=0;i<n*m;i++){
		for(int j=i;j<n*m;j++){
			if(a[i]>a[j]);
			int t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
	}

	for(int i=n*m;i>=0;i--){
		if(a[i]==R){
			y=i/n+1;
			x=i%n+1;
			if(y%2==0){
				x=m-x+1;
			}
			break;
		}
	}
	cout<<y<<" "<<x;
	return 0;
}
