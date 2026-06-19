#include<iostream>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	int k;
	cin>>n;
	cin>>k;
	int a[500005];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==1 and k==0){
		if(a[0]==0){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	}
	if(n==2 and k==0){
		if(a[0]==0 and a[1]==0){
			cout<<"2";
		}
		else if(a[0]==0 and a[1]!=0){
			cout<<"1";
		}
		else if(a[0]!=0 and a[1]==0){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	}
	return 0;
} 
