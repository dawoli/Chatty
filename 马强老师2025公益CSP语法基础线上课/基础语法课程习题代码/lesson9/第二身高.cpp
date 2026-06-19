#include<iostream>
using namespace std;
int main(){
	int n,h[101]={};
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>h[i];
	int Max=0,maxi;
	for(int i=1;i<=n;i++){
		if(h[i]>Max){
			Max=h[i];
			maxi=i;
		}
	}
	//去掉最高的人
	h[maxi]=0;
	Max=0;
	for(int i=1;i<=n;i++){
		if(h[i]>Max){
			Max=h[i];
			maxi=i;
		}
	}
	cout<<maxi<<' '<<h[maxi]<<endl;
	return 0;
}
