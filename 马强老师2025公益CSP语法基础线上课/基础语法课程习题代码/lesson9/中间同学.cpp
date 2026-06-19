#include<iostream>
using namespace std;
int main(){
	int h[101]={};
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>h[i];
	int max=0,maxi;
	int min=1000,mini;
	for(int i=1;i<=n;i++){
		if(max<h[i]){
			max=h[i];maxi=i;
		}
	}
	for(int i=1;i<=n;i++){
		if(min>h[i]){
			min=h[i];mini=i;
		}
	}
	for(int i=maxi+1;i<mini;i++)
		cout<<i<<' '<<h[i]<<endl;
	return 0;
}
