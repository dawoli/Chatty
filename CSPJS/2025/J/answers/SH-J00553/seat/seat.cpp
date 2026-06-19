#include <iostream>
#include <algorithm>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}for(int i=1;i<n*m;i++){
		for(int j=1;j<n*m-i;j++){
			if(a[j]<a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}int mid;
	for(int i=1;i<n*m;i++){
		if(a[i]>a[0]&&a[i+1]<a[0]){
			mid=i+1;
			break;
		}
	}for(int i=n*m-1;i>=mid;i--){
		a[i+1]=a[i];
	}a[mid]=a[0];
	int c=(mid-1)/n+1;
	cout<<c<<" ";
	if(c%2==1){
		if(mid%n==0){
			cout<<n;
		}else{
			cout<<mid%n;
		}
	}else{
		if(mid%n==0){
			cout<<1;
		}else{
			cout<<n-mid%n+1;
		}
	}
	return 0;
}
