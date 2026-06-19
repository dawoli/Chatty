#include <bits/stdc++.h>
using namespace std;
int arr[105],arr2[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a=0,b=0,c,e,n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>arr[i];
	}
	e=arr[0];
	int d=n*m;
	while(d>1){
		for(int i=0;i<d;i++){
			if(arr[i]<arr[i+1]){
				c=arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=c;
			}
		}
		d-=1;
	}
	while(a==0){
		for(int i=0;i<n;i++){
			arr2[i][b]=arr[i+n*b];
			if(arr2[i][b]==e){
				cout<<b+1<<" "<<i+1;
				a=1;
				break;
			}
		}
		if(a==1){
			break;
		}
		b+=1;
		for(int i=n-1;i>=0;i--){
			arr2[i][b]=arr[i+n*b-1];
			if(arr2[i][b]==e){
				cout<<b+1<<" "<<i+1;
				a=1;
				break;
			}
		}
		b+=1;
	}
	return 0;
} 
