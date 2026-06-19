#include<bits/stdc++.h>

using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int x,y;
	cin>>x>>y;
	int arr[105][105]={};
	int k=1,j1=1;
	while(k<x*y){
		if(j1%2==1){
			for(int i=1;i<=x;i++){
				arr[i][j1]=k;
				k++;
			}
		}else{
			for(int i=x;i>=1;i--){
				arr[i][j1]=k;
				k++;
			}
		}
		j1++;
	}
	int arr1[110]={};
	for(int i=1;i<=x*y;i++){
		cin>>arr1[i];
	}
	int p=arr1[1];
	sort(arr1+1,arr1+x*y+1);
	int q=0;
	for(int i=1;i<=x*y;i++){
		if(arr1[i]==p){
			q=x*y-i+1;
			break;
		}
	}
	for(int i=1;i<=x;i++){
		for(int j=1;j<=y;j++){
			if(arr[i][j]==q){
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
}
//9:50 应该是做出来了 后两题不想做了 睡会觉吧
//10:40 我这个代码超不了时吧 
//11:09 被吓到了之差点名字拼音打错 
