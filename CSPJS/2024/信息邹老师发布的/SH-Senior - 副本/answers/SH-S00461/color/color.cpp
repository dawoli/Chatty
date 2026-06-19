#include<iostream>
using namespace std;
int pd(int i,int l,int points,int arr[],bool color[]){
	if(i==l)return points;
	int a=0;
	color[i]=true; 
	for(int j=i-1;j>=0;j--){
		if(color[i]==color[j]){
			if(arr[i]==arr[j])a=arr[i];
			break;
		}
	}
	int cache=pd(i+1,l,points+a,arr,color);
	a=0;
	color[i]=false; 
	for(int j=i-1;j>=0;j--){
		if(color[i]==color[j]){
			if(arr[i]==arr[j])a=arr[i];
			break;
		}
	}
	return max(cache,pd(i+1,l,points+a,arr,color));
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int inquiry;
	cin>>inquiry;
	while(inquiry--){
		int l;
		cin>>l;
		int arr[l];
		for(int i=0;i<l;i++){
			cin>>arr[i];
		}
		bool color[l];
		cout<<pd(0,l,0,arr,color)<<endl;
	}
	return 0;
}

