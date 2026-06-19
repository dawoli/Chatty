#include<bits/stdc++.h>
using namespace std;
int arr[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,mx=INT_MIN;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(arr[i]>mx){
			mx=arr[i];
		}
	}if(n<3){
		cout<<0;
		return 0;
	}if(n==3){
		if(arr[0]+arr[1]+arr[2]>mx*2){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
	return 0;
}
