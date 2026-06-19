#include <iostream>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a1,cnt=0,temp,x,y,a;
	cin>>n>>m;
	int arr1[n*m+1]={};
	for(int i=1;i<=n*m;i++){
		cin>>temp;
		if(i==1) a1=temp;
		arr1[i]=temp;
	}
	int j=n*m+1;
	while(j>0){
		for(int i=1;i<j-1;i++){
			if(arr1[i]<arr1[i+1]){
				a=arr1[i];
				arr1[i]=arr1[i+1];
				arr1[i+1]=a;
			}
		}
		j--;
	}
	
	for(int i=1;i<=n*m;i++){
		if(arr1[i]==a1){
			if(i%m!=0)x=i/m+1;
			else x=i/m;
			if(x%2==0&&i%n!=0)y=n-i%n+1;
			else if(x%2==0&&i%n==0)y=1;
			else if(x%2==1&&i%n==0) y=n;
			else y=i%n;
		}
	}
	cout<<x<<' '<<y;

	
	return 0;
}
