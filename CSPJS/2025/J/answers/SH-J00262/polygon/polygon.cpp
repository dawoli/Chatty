#include <iostream>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int arr[n]={};
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int j=n,a;
	while(j>0){
		for(int i=0;i<j-1;i++){
			if(arr[i]>arr[i+1]){
				a=arr[i];
				arr[i+1]=arr[i];
				arr[i+1]=a;
			}
		}
		j--;
	}
	int cnt=0,temp=0;
	if(n<3) cout<<0;
	
	else if(n==3){
		if(arr[0]+arr[1]>arr[2]) cout<<1;
		else cout<<0;
	}
	
	else if(n==4){
		int arr1[3]={};
		for(int i=0;i<4;i++){
			temp=0;
			for(int j=0;j<4;j++){
				if(j==i)continue;
				arr1[temp]=arr[j];
				temp++;
			}
			if(arr1[0]+arr1[1]>arr1[2]) cnt++;
		}
		if(arr[0]+arr[1]+arr[2]>arr[3]) cnt++;
		cout<<cnt;
	}
	
	else if(n==5){
		int arr1[3]={};
		for(int i=0;i<5;i++){
			for(int k=0;k<i;k++){
				temp=0;
				for(int j=0;j<5;j++){
					if(j==i||j==k)continue;
					arr1[temp]=arr[j];
					temp++;
				}if(arr1[0]+arr1[1]>arr1[2]) cnt++;
			}
		}
		
		int arr2[4]={};
		for(int i=0;i<5;i++){
			temp=0;
			for(int j=0;j<5;j++){
				if(j==i)continue;
				arr2[temp]=arr[j];
				temp++;
			}
			if(arr2[0]+arr2[1]+arr2[2]>arr2[3]) cnt++;
		}
		
		if(arr[0]+arr[1]+arr[2]+arr[3]>arr[4]) cnt++;
		cout<<cnt;
	}
	
	return 0;
}
