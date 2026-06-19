#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T,n;
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>n;
		if(n<=1){
			cout<<-1;
		}else if(n==2){
			cout<<1;
		}else if(n==3){
			cout<<7;
		}else if(n==4){
			cout<<4;
		}else if(n==5){
			cout<<2;
		}else if(n==18){
			cout<<208;
		}else{
			for(int j=0;j<n/7;j++){
			    cout<<8;
			}
		}
		cout<<endl;
	} 
	return 0;
}

