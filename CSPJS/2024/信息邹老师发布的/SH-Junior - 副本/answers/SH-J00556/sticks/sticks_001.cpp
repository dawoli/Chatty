#include<bits/stdc++.h>
using namespace std;
int shu[20]={6,2,5,5,4,5,6,3,7,6};
int n;
int t;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		bool flag=0; 
		for(int i=1;i<10;i++){
			if(shu[i]==n){
				cout<<i<<endl;
				flag=1;
				break;
			}
		}
		if(flag==1){
			continue;
		}
		if(n<2){
			cout<<-1<<endl;
			continue;
		}
		if(n%7==0){
			
		}
		else if(n%7==1){
			cout<<10<<endl;
			n-=8;
		}
		else if(n%7==2){
			cout<<1;
			n-=2;
		}
		else if(n%7==3){
			cout<<200; 
			n-=17;
		}
		else if(n%7==4){
			cout<<20;
			n-=11;
		}
		else if(n%7==5){
			cout<<2;
			n-=5;
		}
		else if(n%7==6){
			cout<<6;
			n-=6;
		}
		for(int i=0;i<n/7;i++){
			cout<<"8";
		}
		cout<<endl;
	}
	return 0;
} 
